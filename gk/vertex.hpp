#ifndef VERTEX_HPP
#define VERTEX_HPP

#include <boost/serialization/utility.hpp>

class vertex
{
public:
	double x;
	double y;
	double z;

	vertex();
	vertex(double x, double y, double z);
	vertex operator+(vertex v);

	template<class A> 
	void serialize(A& archive, const unsigned int)
	{
		archive & BOOST_SERIALIZATION_NVP(x);
		archive & BOOST_SERIALIZATION_NVP(y);
		archive & BOOST_SERIALIZATION_NVP(z);
	}

	void draw();
};

BOOST_CLASS_IMPLEMENTATION(vertex, boost::serialization::object_serializable);

#endif //VERTEX_HPP 