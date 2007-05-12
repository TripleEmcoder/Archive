#include "stair.hpp"
#include "cuboid.hpp"

#include <windows.h>
#include <GL/gl.h>
	
void stair::draw() const
{
	glColor3d(1, 0, 0);
	cuboid vertical(start, vertex(width, height, -thickness));
	vertical.draw();

	glColor3d(0, 1, 0);
	cuboid horizontal(start+vertex(0, height, overhang), vertex(width, thickness, -depth-overhang));
	horizontal.draw();
}