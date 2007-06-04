#include "fps_meter.hpp"
#include "opengl.hpp"

fps_meter::fps_meter()
:
	count(0), previous(glutGet(GLUT_ELAPSED_TIME))
{
}

void fps_meter::draw(const state& state) const
{
	count++;
	
	int current = glutGet(GLUT_ELAPSED_TIME);
	
	if (current - previous > 1000) 
	{
		rate = count*1000.0/(current-previous);
		previous = current;		
		count = 0;
	}

	write(75, 30, "FPS: %6.2f", rate);
}