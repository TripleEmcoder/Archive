#ifndef OBJECTS_WALL_HPP
#define OBJECTS_WALL_HPP

#include <boost/serialization/utility.hpp>

#include "../traits/vector.hpp"

#include "object.hpp"
#include "door.hpp"

class wall : public object
{
public:
	double length;
	double height;
	double thickness;
	std::vector<door> doors;

	template<class A> 
	void serialize(A& archive, const unsigned int version)
	{
		object::serialize(archive, version);
		archive & BOOST_SERIALIZATION_NVP(length);
		archive & BOOST_SERIALIZATION_NVP(height);
		archive & BOOST_SERIALIZATION_NVP(thickness);
		archive & BOOST_SERIALIZATION_NVP(doors);
	}

	void draw() const;
};

BOOST_CLASS_IMPLEMENTATION(wall, boost::serialization::object_serializable);

#endif //OBJECTS_WALL_HPP 