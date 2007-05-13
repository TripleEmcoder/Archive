#include "cuboid.hpp"
#include "material.hpp"

cuboid::cuboid()
{
}

cuboid::cuboid(vertex position, vertex size)
: position(position), size(size)
{
}

#include <windows.h>
#include <GL/gl.h>

void cuboid::draw() const
{
	glBegin(GL_QUADS);
	
	//glColor3d(1,0,0);
	glTexCoord2d(0,0); glVertex3d(position.x,        position.y,        position.z+size.z);
	glTexCoord2d(0,1); glVertex3d(position.x,        position.y+size.y, position.z+size.z);
	glTexCoord2d(1,1); glVertex3d(position.x,        position.y+size.y, position.z       );
	glTexCoord2d(1,0); glVertex3d(position.x,        position.y,        position.z       );

	//glColor3d(1,1,0);
	glTexCoord2d(0,0); glVertex3d(position.x+size.x, position.y,        position.z+size.z);
	glTexCoord2d(0,1); glVertex3d(position.x+size.x, position.y+size.y, position.z+size.z);
	glTexCoord2d(1,1); glVertex3d(position.x+size.x, position.y+size.y, position.z       );
	glTexCoord2d(1,0); glVertex3d(position.x+size.x, position.y,        position.z       );

	//glColor3d(0,1,0);
	glTexCoord2d(0,0); glVertex3d(position.x,        position.y,        position.z+size.z);
	glTexCoord2d(0,1); glVertex3d(position.x,        position.y,        position.z       );
	glTexCoord2d(1,1); glVertex3d(position.x+size.x, position.y,        position.z       );
	glTexCoord2d(1,0); glVertex3d(position.x+size.x, position.y,        position.z+size.z);

	//glColor3d(0,1,1);
	glTexCoord2d(0,0); glVertex3d(position.x,        position.y,        position.z+size.z);
	glTexCoord2d(0,1); glVertex3d(position.x,        position.y,        position.z       );
	glTexCoord2d(1,1); glVertex3d(position.x+size.x, position.y,        position.z       );
	glTexCoord2d(1,0); glVertex3d(position.x+size.x, position.y,        position.z+size.z);

	//glColor3d(0,0,1);
	glTexCoord2d(0,0); glVertex3d(position.x,        position.y,        position.z       );
	glTexCoord2d(0,1); glVertex3d(position.x,        position.y+size.y, position.z       );
	glTexCoord2d(1,1); glVertex3d(position.x+size.x, position.y+size.y, position.z       );
	glTexCoord2d(1,0); glVertex3d(position.x+size.x, position.y,        position.z       );
	
	//glColor3d(1,0,1);
	glTexCoord2d(0,0); glVertex3d(position.x,        position.y,        position.z+size.z);
	glTexCoord2d(0,1); glVertex3d(position.x,        position.y+size.y, position.z+size.z);
	glTexCoord2d(1,1); glVertex3d(position.x+size.x, position.y+size.y, position.z+size.z);
	glTexCoord2d(1,0); glVertex3d(position.x+size.x, position.y,        position.z+size.z);

	glEnd();
}