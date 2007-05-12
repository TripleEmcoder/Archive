#include "staircase.hpp"

#include <windows.h>
#include <GL/gl.h>
	
void staircase::draw() const
{
	stair repeat = model;

	for (int i=0; i<count; i++)
	{
		repeat.start.x = model.start.x;
		repeat.start.y = model.start.y + i*(model.height+model.thickness);
		repeat.start.z = model.start.z - i*(model.depth-model.thickness);

		repeat.draw();
	}
}