#pragma once
#ifndef OBJECTS_BSP_HPP
#define OBJECTS_BSP_HPP

#include <boost/shared_ptr.hpp>
#include <boost/serialization/utility.hpp>

#include "string.hpp"
#include "vector.hpp"
#include "object.hpp"
#include "material.hpp"
#include "texture.hpp"
#include "bsp_struct.hpp"
#include "bezier.hpp"

struct face : public bsp_face
{
	int bezier_id;
	int bezier_count;
	boost::shared_ptr<list_id> list;
	face() : bsp_face(), bezier_id(-1), bezier_count(0) { };
	face(const bsp_face& f) : bsp_face(f), bezier_id(-1), bezier_count(0) { };
};

struct NewtonCollison;
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
	void draw_faces(const std::vector<face>& faces) const;
	void draw_face(const face& face) const;
	void compile_face(face& face) const;
	void create_beziers(face& face);
	void create_collisions() const;
	void add_face(const face& face, const NewtonCollision* tree) const;
	boost::shared_ptr<list_id> _list;

	std::vector<material> _materials;
	std::vector<bsp_vertex> _vertices;
	std::vector<face> _faces;
	std::vector<texture> _textures;
	std::vector<boost::shared_ptr<texture_id> > _lightmaps;
	std::vector<int> _meshverts;
	std::vector<bezier> _beziers;
};

BOOST_CLASS_IMPLEMENTATION(bsp, boost::serialization::object_serializable);

#endif //OBJECTS_BSP_HPP 
