#ifndef HELPERS_VERTEX_HPP
#define HELPERS_VERTEX_HPP

#include <boost/serialization/utility.hpp>

#include "vector.hpp"

class vertex
{
public:
	float x;
	float y;
	float z;

	template<class A> 
	void serialize(A& archive, const unsigned int)
	{
		archive & BOOST_SERIALIZATION_NVP(x);
		archive & BOOST_SERIALIZATION_NVP(y);
		archive & BOOST_SERIALIZATION_NVP(z);
	}

public:
	vertex();
	vertex(float x, float y, float z);
	vertex operator+(const vertex& v) const;

	std::vector<float> vector() const;
};

BOOST_CLASS_IMPLEMENTATION(vertex, boost::serialization::object_serializable);

#endif //HELPERS_VERTEX_HPP
