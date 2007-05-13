#ifndef DOOR_HPP
#define DOOR_HPP

#include <boost/serialization/utility.hpp>

#include "vertex.hpp"

class door
{
public:
	double position;
	double width;
	double height;

	door();
	door(double position, double width, double height);

	template<class A> 
	void serialize(A& archive, const unsigned int)
	{
		archive & BOOST_SERIALIZATION_NVP(position);
		archive & BOOST_SERIALIZATION_NVP(width);
		archive & BOOST_SERIALIZATION_NVP(height);
	}

	void draw() const;
};

BOOST_CLASS_IMPLEMENTATION(door, boost::serialization::object_serializable);

#endif //DOOR_HPP 