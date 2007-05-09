#include "quad.hpp"

#include <windows.h>
#include <GL/gl.h>
	
void quad::draw()
{
	for (size_t i=0; i<vertices.size(); i++)
		vertices[i].draw();
}