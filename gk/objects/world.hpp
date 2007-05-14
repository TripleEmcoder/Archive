#ifndef OBJECTS_WORLD_HPP
#define OBJECTS_WORLD_HPP

#include <istream>
#include <ostream>

#include <boost/serialization/utility.hpp>
#include <boost/shared_ptr.hpp>

#include "../traits/map.hpp"
#include "../traits/vector.hpp"

#include "object.hpp"
#include "material.hpp"
#include "group.hpp"
#include "engine.hpp"

class world : public object
{
public:
	std::map<std::string, material> materials;
	std::vector<group> groups;
	
	template<class A> 
	void serialize(A& archive, const unsigned int version)
	{
		archive & BOOST_SERIALIZATION_NVP(materials);
		object::serialize(archive, version);
		archive & BOOST_SERIALIZATION_NVP(groups);
	}

public:
	const boost::shared_ptr<NewtonWorld> newton;

	world();

	void draw() const;
	void compile();

protected:
	virtual const material* resolve(std::string name) const;
};

BOOST_CLASS_IMPLEMENTATION(world, boost::serialization::object_serializable);

std::istream& operator>> (std::istream& is, world& world);
std::ostream& operator<< (std::ostream& os, const world& world);

#endif //OBJECTS_WORLD_HPP
