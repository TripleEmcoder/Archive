#ifndef OBJECTS_QUAD_HPP
#define OBJECTS_QUAD_HPP

#include <boost/serialization/utility.hpp>

#include "../traits/vector.hpp"

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

	void draw() const;
};

BOOST_CLASS_IMPLEMENTATION(quad, boost::serialization::object_serializable);

#endif //OBJECTS_QUAD_HPP 