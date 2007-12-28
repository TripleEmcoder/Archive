#include "vertex.hpp"

#include <boost/assign/list_of.hpp>

vertex::vertex()
: x(0), y(0), z(0)
{
}

vertex::vertex(float x, float y, float z)
: x(x), y(y), z(z)
{
}

std::vector<float> vertex::vector() const
{
	return boost::assign::list_of(x)(y)(z)(1);
}
