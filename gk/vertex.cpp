#include "vertex.hpp"

vertex::vertex()
{
}

vertex::vertex(double x, double y, double z) : x(x), y(y), z(z)
{
}

vertex vertex::operator+(vertex v) const
{
	return vertex(x+v.x, y+v.y, z+v.z);
}

#include <windows.h>
#include <GL/gl.h>

void vertex::draw() const
{
	glVertex3d(x, y, z);
}