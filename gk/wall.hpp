#ifndef WALL_HPP
#define WALL_HPP

#include <boost/serialization/utility.hpp>

#include "vertex.hpp"
#include "vector.hpp"
#include "door.hpp"

class wall
{
public:
	vertex position;
	double length;
	double height;
	double thickness;
	std::vector<door> doors;

	template<class A> 
	void serialize(A& archive, const unsigned int)
	{
		archive & BOOST_SERIALIZATION_NVP(position);
		archive & BOOST_SERIALIZATION_NVP(length);
		archive & BOOST_SERIALIZATION_NVP(height);
		archive & BOOST_SERIALIZATION_NVP(thickness);
		archive & BOOST_SERIALIZATION_NVP(doors);
	}

	void draw() const;
};

BOOST_CLASS_IMPLEMENTATION(wall, boost::serialization::object_serializable);

#endif //WALL_HPP 