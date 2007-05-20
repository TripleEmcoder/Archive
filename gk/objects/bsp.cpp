#include "bsp.hpp"
#include "scope.hpp"
#include "engine.hpp"
#include "world.hpp"
#include "../math.hpp"

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

void convert(bsp_vertex& vertex)
{
	swap(vertex.position.y, vertex.position.z);
	vertex.position.z = -vertex.position.z;
	vertex.texture_coordinate.y = -vertex.texture_coordinate.y;
}

texture convert_texture(const bsp_texture& t)
{
	texture result(string(t.name) + ".jpg", 0, 0);
	result.compile();
	return result;
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

	void compile()
	{
		NewtonTreeCollisionEndBuild(tree, 0);
		NewtonBody* body = NewtonCreateBody(nWorld, tree);
		
		//Vector p0, p1;
		//Matrix m;
		//NewtonBodyGetMatrix (body, m.data()); 
		//NewtonCollisionCalculateAABB(tree, m.data(), p0.data(), p1.data()); 
		//NewtonSetWorldSize(nWorld, p0.data(), p1.data());

		NewtonReleaseCollision(nWorld, tree);
	}
};

void bsp::compile(const object& parent)
{
	ifstream is;
	bsp_header header;
	bsp_lump lumps[17];
	std::vector<bsp_texture> bsp_textures;
	std::vector<int> meshverts;

	object::compile(parent);

	is.open("map.bsp", ios::binary);

	is.read((char*) &header, sizeof(header));
	is.read((char*) lumps, sizeof(lumps));

	read_lump(is, lumps[Vertexes], _vertices);
	read_lump(is, lumps[Faces], _faces);
	read_lump(is, lumps[Textures], bsp_textures);
	read_lump(is, lumps[Meshverts], meshverts);

	is.close();

	for_each(_vertices.begin(), _vertices.end(), &convert);
	
	_textures.resize(bsp_textures.size());
	transform(bsp_textures.begin(), bsp_textures.end(), _textures.begin(), &convert_texture);

	//const NewtonWorld* nWorld = root().newton();
	//NewtonCollision* tree = NewtonCreateTreeCollision(nWorld, NULL);
	//NewtonTreeCollisionBeginBuild(tree);
	////float square[] = {-500, 0, 500, 
	////				 500, 0, 500,
	////				 500, 0,  -500,
	////				 -500, 0, -500};
	//bsp_vector3f triangle[3];
	//triangle[0] = bsp_vector3f(-500, 200, 500);
	//triangle[1] = bsp_vector3f(500, 200, 500);
	//triangle[2] = bsp_vector3f(0, 200, -500);
	//triangle[0] = {{-500, 200, 500}, {500, 200, 500}, {0, 200, -500}};
	//NewtonTreeCollisionAddFace(tree, 3, (float*)triangle, 12, 1);
	//NewtonTreeCollisionEndBuild(tree, 0);
	//NewtonBody* body = NewtonCreateBody(nWorld, tree);
	//NewtonReleaseCollision(nWorld, tree);

	for_each(_faces.begin(), _faces.end(), mesh_constructor(root().newton(), _vertices, meshverts)).compile();
}

void bsp::draw_face(const bsp_face& face) const
{
	if (face.face_type == polygon)
	{
		glEnable(GL_TEXTURE_2D);
		_textures[face.texture_index].draw();
		//glDisable(GL_TEXTURE_2D);
		glDrawArrays(GL_TRIANGLE_FAN, face.start_vertex_index, face.vertex_count);

		//glBegin(GL_TRIANGLE_FAN);
		//for (int i = face.start_vertex_index; i < face.start_vertex_index + face.vertex_count; ++i)
		//{
		//	const bsp_vertex& v(_vertices[i]);
		//	glNormal3f(v.normal.x, v.normal.y, v.normal.z);
		//	glColor4b(v.color[0], v.color[1], v.color[2], v.color[3]);
		//	glVertex3f(v.position.x, v.position.y, v.position.z);
		//}
		//glEnd();

		assert(glGetError() == GL_NO_ERROR);
	}
}

void bsp::draw() const
{
	//transformation_scope ts(composition());

	glVertexPointer(3, GL_FLOAT, sizeof(bsp_vertex), &_vertices[0].position);
	glTexCoordPointer(2, GL_FLOAT, sizeof(bsp_vertex), &_vertices[0].texture_coordinate);
	glNormalPointer(GL_FLOAT, sizeof(bsp_vertex), &_vertices[0].normal);
	glColorPointer(4, GL_UNSIGNED_BYTE, sizeof(bsp_vertex), &_vertices[0].color);
	
	glEnableClientState(GL_VERTEX_ARRAY);
	glEnableClientState(GL_TEXTURE_COORD_ARRAY);
	glEnableClientState(GL_NORMAL_ARRAY);
	//glEnableClientState(GL_COLOR_ARRAY);

	for_each(_faces.begin(), _faces.end(), boost::bind(&bsp::draw_face, *this, _1));

	glDisableClientState(GL_VERTEX_ARRAY);
	glDisableClientState(GL_TEXTURE_COORD_ARRAY);
	glDisableClientState(GL_NORMAL_ARRAY);
	glDisableClientState(GL_COLOR_ARRAY);

	assert(glGetError() == GL_NO_ERROR);
}
