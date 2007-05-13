#include "stair.hpp"
#include "cuboid.hpp"

#include <windows.h>
#include <GL/gl.h>
	
void stair::draw() const
{
	glColor3d(1, 0, 0);
	cuboid vertical(position, vertex(width, height, -thickness));
	vertical.draw();

	glColor3d(0, 1, 0);
	cuboid horizontal(position+vertex(0, height, overhang), vertex(width, thickness, -depth-overhang));
	horizontal.draw();
}