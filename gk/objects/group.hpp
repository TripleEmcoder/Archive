#ifndef OBJECTS_GROUP_HPP
#define OBJECTS_GROUP_HPP

#include <boost/serialization/utility.hpp>

#include "../traits/string.hpp"
#include "../traits/vector.hpp"

#include "object.hpp"
#include "cuboid.hpp"
#include "staircase.hpp"
#include "wall.hpp"

class group : public object
{
public:
	std::string name;
	bool visible;

	std::vector<cuboid> cuboids;
	std::vector<staircase> staircases;
	std::vector<wall> walls;

	std::vector<group> groups;

	template<class A> 
	void serialize(A& archive, const unsigned int version)
	{
		archive & BOOST_SERIALIZATION_NVP(name);
		archive & BOOST_SERIALIZATION_NVP(visible);

		object::serialize(archive, version);

		archive & BOOST_SERIALIZATION_NVP(cuboids);
		archive & BOOST_SERIALIZATION_NVP(staircases);
		archive & BOOST_SERIALIZATION_NVP(walls);

		archive & BOOST_SERIALIZATION_NVP(groups);
	}

public:
	virtual void draw() const;
	virtual void compile(const object* parent);
};

BOOST_CLASS_IMPLEMENTATION(group, boost::serialization::object_serializable);

#endif //OBJECTS_GROUP_HPP
