#include "vertex.hpp"

#include <windows.h>
#include <GL/gl.h>
	
void vertex::draw()
{
	glVertex3d(x, y, z);
}