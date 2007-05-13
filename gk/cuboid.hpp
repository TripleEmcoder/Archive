#ifndef CUBE_HPP
#define CUBE_HPP

#include <boost/serialization/utility.hpp>

#include "vertex.hpp"

class cuboid
{
public:
	vertex position;
	vertex size;

	cuboid();
	cuboid(vertex position, vertex size);

	template<class A> 
	void serialize(A& archive, const unsigned int)
	{
		archive & BOOST_SERIALIZATION_NVP(position);
		archive & BOOST_SERIALIZATION_NVP(size);
	}

	void draw() const;
};

BOOST_CLASS_IMPLEMENTATION(cuboid, boost::serialization::object_serializable);

#endif //CUBE_HPP 