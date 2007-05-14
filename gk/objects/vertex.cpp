#include "vertex.hpp"

vertex::vertex()
: x(0), y(0), z(0)
{
}

vertex::vertex(float x, float y, float z)
: x(x), y(y), z(z)
{
}

vertex vertex::operator+(vertex v) const
{
	return vertex(x+v.x, y+v.y, z+v.z);
}
