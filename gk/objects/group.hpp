#ifndef OBJECTS_GROUP_HPP
#define OBJECTS_GROUP_HPP

#include <boost/serialization/utility.hpp>

#include "string.hpp"
#include "vector.hpp"

#include "object.hpp"
#include "box.hpp"
#include "ceiling.hpp"
#include "staircase.hpp"
#include "wall.hpp"

class group : public object
{
public:
	std::string name;
	bool visible;

	std::vector<box> boxes;
	std::vector<ceiling> ceilings;
	std::vector<staircase> staircases;
	std::vector<wall> walls;

	std::vector<group> groups;

	template<class A> 
	void serialize(A& archive, const unsigned int version)
	{
		archive & BOOST_SERIALIZATION_NVP(name);
		archive & BOOST_SERIALIZATION_NVP(visible);

		object::serialize(archive, version);

		archive & BOOST_SERIALIZATION_NVP(boxes);
		archive & BOOST_SERIALIZATION_NVP(ceilings);
		archive & BOOST_SERIALIZATION_NVP(staircases);
		archive & BOOST_SERIALIZATION_NVP(walls);

		archive & BOOST_SERIALIZATION_NVP(groups);
	}

public:
	virtual void compile(const object& parent);
	virtual void draw() const;
};

BOOST_CLASS_IMPLEMENTATION(group, boost::serialization::object_serializable);

#endif //OBJECTS_GROUP_HPP
