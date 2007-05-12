#ifndef CUBE_HPP
#define CUBE_HPP

#include <boost/serialization/utility.hpp>

#include "vertex.hpp"

class cuboid
{
public:
	vertex start;
	vertex size;

	cuboid();
	cuboid(vertex start, vertex size);

	template<class A> 
	void serialize(A& archive, const unsigned int)
	{
		archive & BOOST_SERIALIZATION_NVP(start);
		archive & BOOST_SERIALIZATION_NVP(size);
	}

	void draw();
};

BOOST_CLASS_IMPLEMENTATION(cuboid, boost::serialization::object_serializable);

#endif //CUBE_HPP 