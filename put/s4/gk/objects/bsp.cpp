#include "bsp.hpp"
#include "level.hpp"
#include "opengl.hpp"
#include "newton.hpp"
#include "state.hpp"
#include "../Camera.hpp"
#include "../game.hpp"

#include <iostream>
#include <fstream>
#include <boost/bind.hpp>
#include <boost/numeric/conversion/converter.hpp>
#include <boost/numeric/conversion/converter_policies.hpp>
#include <boost/random.hpp>
#include <ctime> 

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

template <typename T> void read_lump(std::ifstream& is, const bsp_lump& lump, std::vector<T>& vec)
{
	is.seekg(lump.offset);
	int n = lump.length / sizeof(T);
	vec.resize(n);
	is.read((char*) &vec[0], n*sizeof(T));
}

template <> void read_lump<bsp_entity*>(std::ifstream& is, const bsp_lump& lump, std::vector<bsp_entity*>& entities)
{
	char* buffer = new char[lump.length];
	is.seekg(lump.offset);
	is.read((char*) buffer, lump.length);
	std::vector<std::string> vec(bsp_entity::split(buffer));
	transform(vec.begin(), vec.end(), back_inserter(entities), boost::bind(&bsp_entity::read, _1));
}

void read_visdata(std::ifstream& is, const bsp_lump& lump, bsp_visdata& visdata)
{
	is.seekg(lump.offset);
	is.read((char*) &visdata.vecs_count, sizeof(visdata.vecs_count));
	is.read((char*) &visdata.vecs_size, sizeof(visdata.vecs_size));
	visdata.vecs = new unsigned char[visdata.vecs_count * visdata.vecs_size];
	is.read((char*) visdata.vecs, visdata.vecs_count * visdata.vecs_size);
}

void overbrighten(unsigned char* color, float scale)
{
	float temp[3];
	float m = 0;
	for (int k = 0; k < 3; ++k)
	{
		temp[k] = color[k] * scale;
		m = max(m, temp[k]);
	}
	if (m > 255.0f)
		for (int k = 0; k < 3; ++k)
			temp[k] *= 255.0f / m;
	for (int k = 0; k < 3; ++k)
		color[k] = temp[k];
}

void convert_vertex(bsp_vertex& vertex)
{
	swizzle(vertex.position);
	swizzle(vertex.normal);
	scale(vertex.position, BSP_SCALE);
	overbrighten(vertex.color, 2.0f);
}

void convert_plane(bsp_plane& plane)
{
	swizzle(plane.normal);
	plane.distance *= BSP_SCALE;
}

template <typename T> void convert_mins_maxs(T& t)
{
	swizzle(t.mins);
	swizzle(t.maxs);
	std::swap(t.mins.z, t.maxs.z);

	using namespace boost::numeric;
	typedef converter<int, float, conversion_traits<int, float>, def_overflow_handler, Ceil<float> > round_ceil; 
	typedef converter<int, float, conversion_traits<int, float>, def_overflow_handler, Floor<float> > round_floor; 
	
	t.mins.x = round_floor::convert(t.mins.x * BSP_SCALE);
	t.mins.y = round_floor::convert(t.mins.y * BSP_SCALE);
	t.mins.z = round_floor::convert(t.mins.z * BSP_SCALE);
	
	t.maxs.x = round_ceil::convert(t.maxs.x * BSP_SCALE);
	t.maxs.y = round_ceil::convert(t.maxs.y * BSP_SCALE);
	t.maxs.z = round_ceil::convert(t.maxs.z * BSP_SCALE);
}

texture convert_texture(const bsp_texture& t)
{
	return texture(t.name);
}

boost::shared_ptr<texture_id> convert_lightmap(bsp_lightmap& l)
{
	boost::shared_ptr<texture_id> id(new texture_id());
	glBindTexture(GL_TEXTURE_2D, *id);

	for (int i = 0; i < 128; ++i)
		for (int j = 0; j < 128; ++j)
			overbrighten(l.pixels[i][j], 3.0f);

	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);

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

template <typename T> bool add_entity(bsp_entity* entity, std::vector<T*>& vec)
{
	T* model = dynamic_cast<T*>(entity);
	if (model)
	{
		vec.push_back(model);
		return true;
	}
	else
		return false;
}

void bsp::create_entities(bsp_entity* entity)
{
	if (add_entity(entity, _model_entities))
		return;
	if (add_entity(entity, _respawn_entities))
		return;
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
	const NewtonWorld* nWorld = root().world().id();
	NewtonCollision* tree = NewtonCreateTreeCollision(nWorld, NULL);
	NewtonTreeCollisionBeginBuild(tree);

	int start = _models[0].start_face_index;
	int end = _models[0].start_face_index + _models[0].face_count;

	for_each(_faces.begin() + start, _faces.begin() + end, boost::bind(&bsp::add_face, boost::ref(*this), _1, tree));

	NewtonTreeCollisionEndBuild(tree, 0);
	NewtonBodySetCollision(body->id(), tree);
	NewtonBodySetMatrix(body->id(), composition().row_major_data());
	NewtonReleaseCollision(nWorld, tree);
}

void bsp::compile(const object& parent)
{
	object::compile(parent);
	body.reset(new body_wrapper(root().world(), name));

	std::ifstream is;
	bsp_header header;
	bsp_lump lumps[17];
	std::vector<bsp_texture> bsp_textures;
	std::vector<bsp_lightmap> bsp_lightmaps;
	std::vector<bsp_face> bsp_faces;
		
	is.open(name.c_str(), std::ios::binary);

	is.read((char*) &header, sizeof(header));
	is.read((char*) lumps, sizeof(lumps));

	read_lump(is, lumps[Vertexes], _vertices);
	read_lump(is, lumps[Meshverts], _meshverts);
	read_lump(is, lumps[Faces], bsp_faces);
	read_lump(is, lumps[Textures], bsp_textures);
	read_lump(is, lumps[Lightmaps], bsp_lightmaps);
	read_lump(is, lumps[Planes], _planes);
	read_lump(is, lumps[Nodes], _nodes);
	read_lump(is, lumps[Leafs], _leafs);
	read_lump(is, lumps[Leaffaces], _leaffaces);
	read_lump(is, lumps[Models], _models);
	read_lump(is, lumps[Entities], _entities);
	read_visdata(is, lumps[Visdata], _visdata);

	is.close();

	for_each(_vertices.begin(), _vertices.end(), &convert_vertex);
	for_each(_planes.begin(), _planes.end(), &convert_plane);
	for_each(_nodes.begin(), _nodes.end(), &convert_mins_maxs<bsp_node>);
	for_each(_leafs.begin(), _leafs.end(), &convert_mins_maxs<bsp_leaf>);
	for_each(_models.begin(), _models.end(), &convert_mins_maxs<bsp_model>);

	
	transform(bsp_textures.begin(), bsp_textures.end(), back_inserter(_textures), &convert_texture);
	transform(bsp_lightmaps.begin(), bsp_lightmaps.end(), back_inserter(_lightmaps), &convert_lightmap);

	copy(bsp_faces.begin(), bsp_faces.end(), back_inserter(_faces));

	for_each(_entities.begin(), _entities.end(), boost::bind(&bsp::create_entities, boost::ref(*this), _1));
	for_each(_faces.begin(), _faces.end(), boost::bind(&bsp::create_beziers, boost::ref(*this), _1));
	for_each(_beziers.begin(), _beziers.end(), boost::bind(&bezier::tessellate, _1, 5));
		
	create_collisions();

	compile_faces();

	_visible_faces.reset(&_faces);

	boost::mt19937 gen(static_cast<unsigned int>(std::time(0))); 
	boost::uniform_int<> dist(0, (int)_respawn_entities.size()-1);

	boost::variate_generator<boost::mt19937&, boost::uniform_int<> > random(gen, dist);  
	int x = random();

	bsp_vector3f pos = _respawn_entities[x]->origin();
	float angle = _respawn_entities[x]->angle();
	game::set_respawn_point(vertex(pos.x, pos.y, pos.z));
	game::set_respawn_angle(angle);
}

void bsp::compile_face(face& face)
{
	face.list.reset(new list_wrapper());
	list_scope ls(*face.list);

	if (face.face_type == polygon || face.face_type == mesh)
	{
		const int offset = face.start_vertex_index;
		const int stride = sizeof(bsp_vertex);
		
		glVertexPointer(3, GL_FLOAT, stride, &_vertices[offset].position);
		glNormalPointer(GL_FLOAT, stride, &_vertices[offset].normal);
		glColorPointer(4, GL_UNSIGNED_BYTE, stride, &_vertices[offset].color);

		glClientActiveTexture(GL_TEXTURE0);
		glTexCoordPointer(2, GL_FLOAT, stride, &_vertices[offset].texture_coordinate);
		glEnableClientState(GL_TEXTURE_COORD_ARRAY);

		glClientActiveTexture(GL_TEXTURE1);
		glTexCoordPointer(2, GL_FLOAT, stride, &_vertices[offset].lightmap_coordinate);
		glEnableClientState(GL_TEXTURE_COORD_ARRAY);

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
	glEnableClientState(GL_NORMAL_ARRAY);
	glEnableClientState(GL_COLOR_ARRAY);

	for_each(_faces.begin(), _faces.end(), boost::bind(&bsp::compile_face, boost::ref(*this), _1));

	glPopClientAttrib();
}

void bsp::draw_face(const face* face, const state& state) const
{
	if (state.settings[LIGHTING_MODE] == LIGHTING_MODE_LIGHTMAP && face->lightmap_index >= 0)
	{
		glActiveTexture(GL_TEXTURE0);
		glEnable(GL_TEXTURE_2D);
		glTexEnvi(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_REPLACE);
		_textures[face->texture_index].draw();

		glActiveTexture(GL_TEXTURE1);
		glEnable(GL_TEXTURE_2D);
		glTexEnvi(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_MODULATE);
		glBindTexture(GL_TEXTURE_2D, *_lightmaps[face->lightmap_index]);
	}
	else 
	{
		glActiveTexture(GL_TEXTURE0);
		glEnable(GL_TEXTURE_2D);
		glTexEnvi(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_MODULATE);
		_textures[face->texture_index].draw();

		glActiveTexture(GL_TEXTURE1);
		glDisable(GL_TEXTURE_2D);
	}

	face->list->call();
}

template <typename T> void bsp::draw_faces(const T& faces, const state& state) const
{
	glPushAttrib(GL_CURRENT_BIT | GL_ENABLE_BIT | GL_LIGHTING_BIT | GL_POLYGON_BIT | GL_TEXTURE_BIT);

	glEnable(GL_CULL_FACE);
	glCullFace(GL_BACK);
	glFrontFace(GL_CW);

	//glEnable(GL_BLEND);
	//glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

	glEnable(GL_COLOR_MATERIAL);
	glColorMaterial(GL_FRONT_AND_BACK, GL_AMBIENT_AND_DIFFUSE);

	for_each(faces.begin(), faces.end(), boost::bind(&bsp::draw_face, boost::ref(*this), _1, boost::ref(state)));

	glPopAttrib();
	assert(glGetError() == GL_NO_ERROR);
}

void bsp::draw(const state& state) const
{
	find_visible_faces(state);
	object::draw(state);
	matrix_scope ms(composition());
	draw_faces(_visible_faces, state);
	for_each(_model_entities.begin(), _model_entities.end(), boost::bind(&bsp_model_entity::draw, _1));
}

void bsp::find_visible_faces(const state& state) const
{
	_visible_faces.clear();

	int camera_cluster = _leafs[find_leaf(state.camera.getPosition())].cluster;

	for (int i = 0; i < (int)_leafs.size(); ++i)
	{
		const bsp_leaf& leaf = _leafs[i];
		const int mins[] = {leaf.mins.x, leaf.mins.y, leaf.mins.z};
		const int maxs[] = {leaf.maxs.x, leaf.maxs.y, leaf.maxs.z};
		if (is_cluster_visible(camera_cluster, leaf.cluster) && state.camera.isVisible(mins, maxs))
		{
			for (int j = 0; j < leaf.leaffaces_count; ++j) 
			{
				const int f = _leaffaces[leaf.start_leafface_index + j];
				_visible_faces.push_back(f);
			}
		}
	}
}

int bsp::find_leaf(const Vector& camera_position) const
{
	int index = 0;

	while (index >= 0)
	{
		const bsp_node& node = _nodes[index];
		const bsp_plane& plane = _planes[node.plane];
		Vector normal = createVector(plane.normal.x, plane.normal.y, plane.normal.z, 0);

		// Distance from point to a plane
		const float distance = inner_prod(normal, camera_position) - plane.distance;

		index = (distance >= 0) ? node.front : node.back;
	}

	return -index - 1;
}

bool bsp::is_cluster_visible(int visible_cluster, int test_cluster) const 
{
    if ((_visdata.vecs == NULL) || (visible_cluster < 0)) 
	{
        return true;
    }

    int i = (visible_cluster * _visdata.vecs_size) + (test_cluster >> 3);
    unsigned char visible_set = _visdata.vecs[i];

    return (visible_set & (1 << (test_cluster & 7))) != 0;
} 
