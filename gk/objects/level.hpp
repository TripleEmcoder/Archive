#ifndef OBJECTS_WORLD_HPP
#define OBJECTS_WORLD_HPP

#include <istream>
#include <ostream>

#include <boost/shared_ptr.hpp>
#include <boost/serialization/utility.hpp>

#include "map.hpp"
#include "vector.hpp"

#include "object.hpp"
#include "material.hpp"
#include "character.hpp"
#include "group.hpp"
#include "newton.hpp"

class level : public object
{
private:
	world_wrapper _world;

public:
	std::map<std::string, material> materials;
	character player;
	std::vector<group> groups;
	
	template<class A> 
	void serialize(A& archive, const unsigned int version)
	{
		archive & BOOST_SERIALIZATION_NVP(materials);
		object::serialize(archive, version);
		archive & BOOST_SERIALIZATION_NVP(player);
		archive & BOOST_SERIALIZATION_NVP(groups);
	}

public:
	void compile();
	void draw(const state& state) const;

	virtual const world_wrapper& world() const;
	virtual const material& bound_material(std::string name) const;
};

BOOST_CLASS_IMPLEMENTATION(level, boost::serialization::object_serializable);

std::istream& operator>> (std::istream& is, level& value);
std::ostream& operator<< (std::ostream& os, const level& value);

#endif //OBJECTS_WORLD_HPP
