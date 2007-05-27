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

class world : public object
{
private:
	world_id _newton;

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

	virtual const world_id& newton() const;
	virtual const material& bound_material(std::string name) const;
};

BOOST_CLASS_IMPLEMENTATION(world, boost::serialization::object_serializable);

std::istream& operator>> (std::istream& is, world& world);
std::ostream& operator<< (std::ostream& os, const world& world);

#endif //OBJECTS_WORLD_HPP
