#include "staircase.hpp"

#include <windows.h>
#include <GL/gl.h>
	
void staircase::draw() const
{
	stair instance(model);

	for (int i=0; i<count; i++)
	{
		instance.position.x = model.position.x;
		instance.position.y = model.position.y + i*model.height;
		instance.position.z = model.position.z - i*model.depth;

		instance.draw();
	}
}