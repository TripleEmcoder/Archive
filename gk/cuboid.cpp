#include "cuboid.hpp"

cuboid::cuboid()
{
}

cuboid::cuboid(vertex start, vertex size) : start(start), size(size)
{
}

#include <windows.h>
#include <GL/gl.h>

void cuboid::draw()
{
	glBegin(GL_QUADS);
	
	//glColor3d(1,0,0);
	glVertex3d(start.x,        start.y,        start.z+size.z);
	glVertex3d(start.x,        start.y+size.y, start.z+size.z);
	glVertex3d(start.x,        start.y+size.y, start.z       );
	glVertex3d(start.x,        start.y,        start.z       );

	//glColor3d(1,1,0);
	glVertex3d(start.x+size.x, start.y,        start.z+size.z);
	glVertex3d(start.x+size.x, start.y+size.y, start.z+size.z);
	glVertex3d(start.x+size.x, start.y+size.y, start.z       );
	glVertex3d(start.x+size.x, start.y,        start.z       );

	//glColor3d(0,1,0);
	glVertex3d(start.x,        start.y,        start.z+size.z);
	glVertex3d(start.x,        start.y,        start.z       );
	glVertex3d(start.x+size.x, start.y,        start.z       );
	glVertex3d(start.x+size.x, start.y,        start.z+size.z);

	//glColor3d(0,1,1);
	glVertex3d(start.x,        start.y,        start.z+size.z);
	glVertex3d(start.x,        start.y,        start.z       );
	glVertex3d(start.x+size.x, start.y,        start.z       );
	glVertex3d(start.x+size.x, start.y,        start.z+size.z);

	//glColor3d(0,0,1);
	glVertex3d(start.x,        start.y,        start.z       );
	glVertex3d(start.x,        start.y+size.y, start.z       );
	glVertex3d(start.x+size.x, start.y+size.y, start.z       );
	glVertex3d(start.x+size.x, start.y,        start.z       );
	
	//glColor3d(1,0,1);
	glVertex3d(start.x,        start.y,        start.z+size.z);
	glVertex3d(start.x,        start.y+size.y, start.z+size.z);
	glVertex3d(start.x+size.x, start.y+size.y, start.z+size.z);
	glVertex3d(start.x+size.x, start.y,        start.z+size.z);

	glEnd();
}