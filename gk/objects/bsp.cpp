#include "bsp.hpp"
#include "scope.hpp"
#include "engine.hpp"
#include "world.hpp"
#include "matrix.hpp"
//#include "../math.hpp"

#include <iostream>
#include <fstream>
#include <boost/bind.hpp>

using namespace std;

enum lump_id
{
	Entities, // Game-related object descriptions. 
	Textures, // Surface descriptions. 
	Planes, // Planes used by map geometry. 
	Nodes, // BSP tree nodes. 
	Leafs, // BSP tree leaves. 
	Leaffaces, // Lists of face indices, one list per leaf. 
	Leafbrushes, // Lists of brush indices, one list per leaf. 
	Models, // Descriptions of rigid world geometry in map. 
	Brushes, // Convex polyhedra used to describe solid space. 
	Brushsides, // Brush surfaces. 
	Vertexes, // Vertices used to describe faces. 
	Meshverts, // Lists of offsets, one list per mesh. 
	Effects, // List of special map effects. 
	Faces, // Surface geometry. 
	Lightmaps, // Packed lightmap data. 
	Lightvols, // Local illumination data. 
	Visdata // Cluster-cluster visibility data.
};

enum face_type
{
	polygon = 1,
	patch,
	mesh,
	billboard
};

template <typename T> void read_lump(ifstream& is, const bsp_lump& lump, std::vector<T>& vec)
{
	is.seekg(lump.offset);
	int n = lump.length / sizeof(T);
	vec.resize(n);
	is.read((char*) &vec[0], n*sizeof(T));
}

void convert_vertex(bsp_vertex& vertex)
{
	swap(vertex.position.y, vertex.position.z);
	vertex.position.z = -vertex.position.z;
	//vertex.texture_coordinate.y = -vertex.texture_coordinate.y;
	float scale = 50.0f;
	vertex.position.x /= scale;
	vertex.position.y /= scale;
	vertex.position.z /= scale;
}

texture convert_texture(const bsp_texture& t)
{
	ifstream file;
	string name = string(t.name) + ".jpg";
	file.open(name.c_str());
	if (!file.is_open())
	{
		name = string(t.name) + ".tga";
		file.open(name.c_str());
	}
	if (file.is_open())
	{
		file.close();
		texture result(name);
		result.compile();
		return result;
	}
	else
	{
		cerr << "Texture not found: " << t.name << endl;
		return texture();
	}
}

boost::shared_ptr<texture_id> convert_lightmap(const bsp_lightmap& l)
{
	boost::shared_ptr<texture_id> id(new texture_id());
	glBindTexture(GL_TEXTURE_2D, *id);
	glTexImage2D(GL_TEXTURE_2D, 0, 3, 128, 128, 0, GL_RGB, GL_UNSIGNED_BYTE, l.pixels);
	return id;
}

struct mesh_constructor
{
	const NewtonWorld* nWorld;
	const std::vector<bsp_vertex>& vertices;
	const std::vector<int>& meshverts;
	NewtonCollision* tree;

	mesh_constructor(const NewtonWorld* nWorld, const std::vector<bsp_vertex>& vertices, const std::vector<int>& meshverts)
		:nWorld(nWorld), vertices(vertices), meshverts(meshverts)
	{
		tree = NewtonCreateTreeCollision(nWorld, NULL);
		NewtonTreeCollisionBeginBuild(tree);
	}

	void operator()(const bsp_face& face)
	{
		for (int i = 0; i < face.mesh_vertex_count; i += 3)
		{
			bsp_vector3f triangle[3];
			for (int j = 0; j < 3; ++j)
			{
				int vert_index = face.start_vertex_index + meshverts[face.start_mesh_vertex_index + i + j];
				const bsp_vertex& v = vertices[vert_index];
				triangle[j] = v.position;
			}
			NewtonTreeCollisionAddFace(tree, 3, (float*)triangle, sizeof(bsp_vector3f), 1); 
			swap(triangle[0], triangle[1]);
			NewtonTreeCollisionAddFace(tree, 3, (float*)triangle, sizeof(bsp_vector3f), 1);
		}
	}

	void compile(const matrix& composition)
	{
		NewtonTreeCollisionEndBuild(tree, 0);
		NewtonBody* body = NewtonCreateBody(nWorld, tree);
		NewtonBodySetMatrix(body, composition.row_major_data());
		//Vector p0, p1;
		//Matrix m;
		//NewtonBodyGetMatrix (body, m.data()); 
		//NewtonCollisionCalculateAABB(tree, m.data(), p0.data(), p1.data()); 
		//NewtonSetWorldSize(nWorld, p0.data(), p1.data());

		NewtonReleaseCollision(nWorld, tree);
	}
};

struct drawer
{
	const std::vector<bsp_vertex>& vertices;
	const std::vector<int>& meshverts;
	const std::vector<texture>& textures;
	const std::vector<boost::shared_ptr<texture_id> >& lightmaps;

	drawer(const std::vector<bsp_vertex>& vertices, const std::vector<int>& meshverts, const std::vector<texture>& textures, const std::vector<boost::shared_ptr<texture_id> >& lightmaps)
		:vertices(vertices), meshverts(meshverts), textures(textures), lightmaps(lightmaps)
	{
		glPushClientAttrib(GL_CLIENT_VERTEX_ARRAY_BIT);
		glPushAttrib(GL_ENABLE_BIT |GL_POLYGON_BIT);

		glEnableClientState(GL_VERTEX_ARRAY);
		glEnableClientState(GL_TEXTURE_COORD_ARRAY);
		//glEnableClientState(GL_NORMAL_ARRAY);
		//glEnableClientState(GL_COLOR_ARRAY);

		glEnable(GL_TEXTURE_2D);
		//glFrontFace(GL_CW);
		//glCullFace(GL_BACK);
		//glEnable(GL_CULL_FACE);
	}

	void operator()(const bsp_face& face)
	{
		if (face.face_type == polygon || face.face_type == mesh)
		{
			const int offset = face.start_vertex_index;
			const int stride = sizeof(bsp_vertex);
			
			glVertexPointer(3, GL_FLOAT, stride, &vertices[offset].position);

			glClientActiveTexture(GL_TEXTURE0);
			textures[face.texture_index].draw();
			glTexCoordPointer(2, GL_FLOAT, stride, &vertices[offset].texture_coordinate);

			if (face.lightmap_index != -1)
			{
				glClientActiveTexture(GL_TEXTURE1);
				glBindTexture(GL_TEXTURE_2D, *lightmaps[face.lightmap_index]);
				glTexCoordPointer(2, GL_FLOAT, stride, &vertices[offset].lightmap_coordinate);
			}

			glDrawElements(GL_TRIANGLES, face.mesh_vertex_count, GL_UNSIGNED_INT, &meshverts[face.start_mesh_vertex_index]);
		}
	}

	void finish()
	{
		glPopAttrib();
		glPopClientAttrib();
		assert(glGetError() == GL_NO_ERROR);
	}
};

void bsp::compile(const object& parent)
{
	ifstream is;
	bsp_header header;
	bsp_lump lumps[17];
	std::vector<bsp_texture> bsp_textures;
	std::vector<bsp_lightmap> bsp_lightmaps;

	object::compile(parent);

	is.open(name.c_str(), ios::binary);

	is.read((char*) &header, sizeof(header));
	is.read((char*) lumps, sizeof(lumps));

	read_lump(is, lumps[Vertexes], _vertices);
	read_lump(is, lumps[Meshverts], _meshverts);
	read_lump(is, lumps[Faces], _faces);
	read_lump(is, lumps[Textures], bsp_textures);
	read_lump(is, lumps[Lightmaps], bsp_lightmaps);

	is.close();

	for_each(_vertices.begin(), _vertices.end(), &convert_vertex);
	
	_textures.resize(bsp_textures.size());
	transform(bsp_textures.begin(), bsp_textures.end(), _textures.begin(), &convert_texture);

	_lightmaps.resize(bsp_lightmaps.size());
	transform(bsp_lightmaps.begin(), bsp_lightmaps.end(), _lightmaps.begin(), &convert_lightmap);

	for_each(_faces.begin(), _faces.end(), mesh_constructor(root().newton(), _vertices, _meshverts)).compile(composition());

	_list.reset(new list_id());
	list_scope ls(*_list);
	object::draw();
	
	{
		matrix_scope ms(composition());
		for_each(_faces.begin(), _faces.end(), drawer(_vertices, _meshverts, _textures, _lightmaps)).finish();;
	}
}

void bsp::draw() const
{
	glCallList(*_list);
}
