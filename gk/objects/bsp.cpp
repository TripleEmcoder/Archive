#include "bsp.hpp"
#include "scope.hpp"
#include "engine.hpp"
#include "world.hpp"
#include "matrix.hpp"
#include "state.hpp"
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

	swap(vertex.normal.y, vertex.normal.z);
	vertex.normal.z = -vertex.normal.z;

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

void bsp::create_beziers(face& face)
{
	if (face.face_type == patch)
		{
			face.bezier_id = (int)_beziers.size();
			face.bezier_count = ((face.size[0] - 1) / 2) * ((face.size[1] - 1) / 2);
			for (int n = 0; n < (face.size[0] - 1) / 2; ++n)
				for (int m = 0; m < (face.size[1] - 1) / 2; ++m)
				{
					bsp_vertex controls[9];
					const int offset = face.start_vertex_index + 2*m*face.size[0] + 2*n;
					for (int p = 0; p < 3; ++p)
						for (int q = 0; q < 3; ++q)
							controls[p*3 + q] = _vertices[offset + p*face.size[0] + q];
					_beziers.push_back(bezier(controls));
				}
		}
}

void bsp::add_face(const face& face, const NewtonCollision* tree) const
{
	if (face.face_type == polygon || face.face_type == mesh)
	{
		for (int i = 0; i < face.mesh_vertex_count; i += 3)
		{
			bsp_vector3f triangle[3];
			for (int j = 0; j < 3; ++j)
			{
				int vert_index = face.start_vertex_index + _meshverts[face.start_mesh_vertex_index + i + j];
				const bsp_vertex& v = _vertices[vert_index];
				triangle[2-j] = v.position;
			}
			NewtonTreeCollisionAddFace(tree, 3, (float*)triangle, sizeof(bsp_vector3f), 1);
		}
	}
	else if (face.face_type == patch)
	{
		for (int i = 0; i < face.bezier_count; ++i)
			_beziers[face.bezier_id+i].add_faces(tree);
	}
}

void bsp::create_collisions() const
{
	const NewtonWorld* nWorld = root().newton();
	NewtonCollision* tree = NewtonCreateTreeCollision(nWorld, NULL);
	NewtonTreeCollisionBeginBuild(tree);

	for_each(_faces.begin(), _faces.end(), boost::bind(&bsp::add_face, boost::ref(*this), _1, tree));

	NewtonTreeCollisionEndBuild(tree, 0);
	NewtonBody* body = NewtonCreateBody(nWorld, tree);
	NewtonBodySetMatrix(body, composition().row_major_data());
	//Vector p0, p1;
	//Matrix m;
	//NewtonBodyGetMatrix (body, m.data()); 
	//NewtonCollisionCalculateAABB(tree, m.data(), p0.data(), p1.data()); 
	//NewtonSetWorldSize(nWorld, p0.data(), p1.data());

	NewtonReleaseCollision(nWorld, tree);
}

void bsp::compile(const object& parent)
{
	ifstream is;
	bsp_header header;
	bsp_lump lumps[17];
	std::vector<bsp_texture> bsp_textures;
	std::vector<bsp_lightmap> bsp_lightmaps;
	std::vector<bsp_face> bsp_faces;
	
	object::compile(parent);

	is.open(name.c_str(), ios::binary);

	is.read((char*) &header, sizeof(header));
	is.read((char*) lumps, sizeof(lumps));

	read_lump(is, lumps[Vertexes], _vertices);
	read_lump(is, lumps[Meshverts], _meshverts);
	read_lump(is, lumps[Faces], bsp_faces);
	read_lump(is, lumps[Textures], bsp_textures);
	read_lump(is, lumps[Lightmaps], bsp_lightmaps);

	is.close();

	for_each(_vertices.begin(), _vertices.end(), &convert_vertex);
	
	transform(bsp_textures.begin(), bsp_textures.end(), back_inserter(_textures), &convert_texture);
	transform(bsp_lightmaps.begin(), bsp_lightmaps.end(), back_inserter(_lightmaps), &convert_lightmap);

	copy(bsp_faces.begin(), bsp_faces.end(), back_inserter(_faces));

	for_each(_faces.begin(), _faces.end(), boost::bind(&bsp::create_beziers, boost::ref(*this), _1));
	for_each(_beziers.begin(), _beziers.end(), boost::bind(&bezier::tessellate, _1, 5));

	create_collisions();

	compile_faces();

	//_list.reset(new list_id());
	//list_scope ls(*_list);
	//state state;
	//object::draw(state);

	//{
	//	matrix_scope ms(composition());
	//	draw_faces(_faces);
	//}
}

void bsp::compile_face(face& face)
{
	face.list.reset(new list_id());
	list_scope ls(*face.list);

	glActiveTexture(GL_TEXTURE0);
	_textures[face.texture_index].draw();

	if (face.lightmap_index != -1)
	{
		glActiveTexture(GL_TEXTURE1);
		glBindTexture(GL_TEXTURE_2D, *_lightmaps[face.lightmap_index]);
	}

	if (face.face_type == polygon || face.face_type == mesh)
	{
		const int offset = face.start_vertex_index;
		const int stride = sizeof(bsp_vertex);
		
		glVertexPointer(3, GL_FLOAT, stride, &_vertices[offset].position);
		glNormalPointer(GL_FLOAT, stride, &_vertices[offset].normal);
		glColorPointer(4, GL_UNSIGNED_BYTE, stride, &_vertices[offset].color);

		glClientActiveTexture(GL_TEXTURE0);
		glTexCoordPointer(2, GL_FLOAT, stride, &_vertices[offset].texture_coordinate);

		glClientActiveTexture(GL_TEXTURE1);
		glTexCoordPointer(2, GL_FLOAT, stride, &_vertices[offset].lightmap_coordinate);

		glDrawElements(GL_TRIANGLES, face.mesh_vertex_count, GL_UNSIGNED_INT, &_meshverts[face.start_mesh_vertex_index]);
	}
	else if (face.face_type == patch)
	{
		for (int i = 0; i < face.bezier_count; ++i)
			_beziers[face.bezier_id+i].draw();
	}
}

void bsp::compile_faces()
{
	glPushClientAttrib(GL_CLIENT_VERTEX_ARRAY_BIT);
	
	glEnableClientState(GL_VERTEX_ARRAY);
	glEnableClientState(GL_TEXTURE_COORD_ARRAY);
	glEnableClientState(GL_NORMAL_ARRAY);
	glEnableClientState(GL_COLOR_ARRAY);

	for_each(_faces.begin(), _faces.end(), boost::bind(&bsp::compile_face, boost::ref(*this), _1));

	glPopClientAttrib();
}

void bsp::draw_face(const face& face) const
{
	glCallList(*face.list);
}

void bsp::draw_faces(const vector<face>& faces) const
{
	glPushClientAttrib(GL_CLIENT_VERTEX_ARRAY_BIT);
	glPushAttrib(GL_ENABLE_BIT |GL_POLYGON_BIT | GL_TEXTURE_BIT);

	glEnable(GL_TEXTURE_2D);
	glFrontFace(GL_CW);
	glCullFace(GL_BACK);
	glEnable(GL_CULL_FACE);

	for_each(faces.begin(), faces.end(), boost::bind(&bsp::draw_face, boost::ref(*this), _1));
	//for (int i = 0; i < faces.size(); i+=3)
	//	draw_face(_faces[i]);

	glPopAttrib();
	glPopClientAttrib();
	assert(glGetError() == GL_NO_ERROR);
}

void bsp::draw(const state& state) const
{
	//glCallList(*_list);
	object::draw(state);
	matrix_scope ms(composition());
	draw_faces(_faces);
}
