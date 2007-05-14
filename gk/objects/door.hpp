#ifndef OBJECTS_DOOR_HPP
#define OBJECTS_DOOR_HPP

#include <boost/serialization/utility.hpp>

class door
{
public:
	float offset;
	float width;
	float height;

	template<class A> 
	void serialize(A& archive, const unsigned int)
	{
		archive & BOOST_SERIALIZATION_NVP(offset);
		archive & BOOST_SERIALIZATION_NVP(width);
		archive & BOOST_SERIALIZATION_NVP(height);
	}

public:
	door();
	door(float offset, float width, float height);
};

BOOST_CLASS_IMPLEMENTATION(door, boost::serialization::object_serializable);

#endif //OBJECTS_DOOR_HPP 