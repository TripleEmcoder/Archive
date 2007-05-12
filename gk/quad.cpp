#include "quad.hpp"

#include <windows.h>
#include <GL/gl.h>
	
void quad::draw()
{
	glBegin(GL_QUADS);

	for (size_t i=0; i<vertices.size(); i++)
		vertices[i].draw();

	glEnd();
}