#pragma once
#ifndef OBJECTS_BSP_HPP
#define OBJECTS_BSP_HPP

#include <boost/shared_ptr.hpp>
#include <boost/serialization/utility.hpp>
#include <set>

#include "string.hpp"
#include "vector.hpp"
#include "object.hpp"
#include "material.hpp"
#include "texture.hpp"
#include "bsp_common.hpp"
#include "bezier.hpp"
#include "matrix.hpp"
#include "opengl.hpp"
#include "newton.hpp"
#include "../math.hpp"
#include "../widgets/widget.hpp"
#include "../set_vector.hpp"
#include "../helpers/bsp_entity.hpp"

struct face : public bsp_face
{
	int bezier_id;
	int bezier_count;
	boost::shared_ptr<list_wrapper> list;
	face() : bsp_face(), bezier_id(-1), bezier_count(0) { };
	face(const bsp_face& f) : bsp_face(f), bezier_id(-1), bezier_count(0) { };
};

struct NewtonCollison;
class body_wrapper;

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
	virtual void draw(const state& state) const;

private:
	template <typename T> void draw_faces(const T& faces, const state& state) const;
	void draw_face(const face* face, const state& state) const;
	void compile_faces();
	void compile_face(face& face);
	void create_beziers(face& face);
	void create_collisions() const;
	void add_face(const face& face, const NewtonCollision* tree) const;

	void find_visible_faces(const state& state) const;
	int find_leaf(const Vector& camera_position) const;
	bool is_cluster_visible(int visible_cluster, int test_cluster) const;


	boost::shared_ptr<list_id> _list;

	std::vector<material> _materials;
	std::vector<bsp_vertex> _vertices;
	std::vector<face> _faces;
	std::vector<texture> _textures;
	std::vector<boost::shared_ptr<texture_id> > _lightmaps;
	std::vector<int> _meshverts;
	std::vector<bezier> _beziers;
	std::vector<bsp_plane> _planes;
	std::vector<bsp_node> _nodes;
	std::vector<bsp_leaf> _leafs;
	std::vector<int> _leaffaces;
	std::vector<bsp_model> _models;
	std::vector<bsp_entity> _entities;
	bsp_visdata _visdata;

	mutable set_vector<face> _visible_faces;
	
	boost::shared_ptr<body_wrapper> body;
};

BOOST_CLASS_IMPLEMENTATION(bsp, boost::serialization::object_serializable);

#endif //OBJECTS_BSP_HPP 
