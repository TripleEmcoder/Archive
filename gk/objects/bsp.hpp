#ifndef OBJECTS_BSP_HPP
#define OBJECTS_BSP_HPP

#include <boost/shared_ptr.hpp>
#include <boost/serialization/utility.hpp>

#include "string.hpp"
#include "vector.hpp"
#include "object.hpp"
#include "material.hpp"
#include "texture.hpp"

struct bsp_vector3i
{
	int x, y, z;
};

struct bsp_vector2f
{
	float x, y;
};

struct bsp_vector3f
{
	bsp_vector3f(float x = 0.0f, float y = 0.0f, float z = 0.0f) : x(x), y(y), z(z) { };
	float x, y, z;
};

struct bsp_header
{
	char id[4];
	int version;
};

struct bsp_lump
{
	int offset;
	int length;
};

struct bsp_vertex
{
	bsp_vector3f position;
	bsp_vector2f texture_coordinate;
	bsp_vector2f lightmap_coordinate;
	bsp_vector3f normal;
	unsigned char color[4];
};

struct bsp_face
{
	int texture_index;
	int effect_index;
	int face_type;
	int start_vertex_index;
	int vertex_count;
	int start_mesh_vertex_index;
	int mesh_vertex_count;
	int lightmap_index;
	int lightmap_corner[2];
	int lightmap_size[2];
	bsp_vector3f lightmap_origin;
	bsp_vector3f lightmap_vectors[2];
	bsp_vector3f normal;
	int size[2];
};

struct bsp_texture
{
	char name[64];
	int flags;
	int contents;
};

struct bsp_lightmap
{
	char pixels[128][128][3];
};

class bsp : public object
{
public:
	std::string name;

	template<class A> 
	void serialize(A& archive, const unsigned int version)
	{
		object::serialize(archive, version);
		archive & BOOST_SERIALIZATION_NVP(name);
	}

public:
	virtual void compile(const object& parent);
	virtual void draw() const;

private:
	void draw_face(const bsp_face& face) const;

private:
	std::vector<material> _materials;
	std::vector<bsp_vertex> _vertices;
	std::vector<bsp_face> _faces;
	std::vector<texture> _textures;
};

BOOST_CLASS_IMPLEMENTATION(bsp, boost::serialization::object_serializable);

#endif //OBJECTS_BSP_HPP 
