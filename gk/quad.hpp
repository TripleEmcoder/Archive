#ifndef QUAD_HPP
#define QUAD_HPP

#include <boost/serialization/utility.hpp>

#include "vector.hpp"
#include "vertex.hpp"

class quad
{
public:
	std::vector<vertex> vertices;

	template<class A> 
	void serialize(A& archive, const unsigned int)
	{
		archive & BOOST_SERIALIZATION_NVP(vertices);
	}

	void draw();
};

BOOST_CLASS_IMPLEMENTATION(quad, boost::serialization::object_serializable);

#endif //PLANE_HPP 