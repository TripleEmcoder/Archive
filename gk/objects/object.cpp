#include "object.hpp"

object::object()
{
}

object::object(vertex position)
: position(position)
{
}

#include <windows.h>
#include <GL/gl.h>

void object::draw() const
{
	glTranslated(position.x, position.y, position.z);
	glRotated(rotation.x, 1, 0, 0);
	glRotated(rotation.y, 0, 1, 0);
	glRotated(rotation.z, 0, 0, 1);
}
