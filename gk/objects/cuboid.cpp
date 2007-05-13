#include "cuboid.hpp"
#include "material.hpp"

cuboid::cuboid()
{
}

cuboid::cuboid(vertex position, vertex size)
: object(position), size(size)
{
}

#include <windows.h>
#include <GL/gl.h>

void cuboid::draw() const
{
	std::map<std::string, material> materials(materials);

	//glColor3d(1,0,0);
	materials["left"].draw();
	glBegin(GL_QUADS);
	glTexCoord2d(0,0); glVertex3d(position.x,        position.y,        position.z+size.z);
	glTexCoord2d(0,1); glVertex3d(position.x,        position.y+size.y, position.z+size.z);
	glTexCoord2d(1,1); glVertex3d(position.x,        position.y+size.y, position.z       );
	glTexCoord2d(1,0); glVertex3d(position.x,        position.y,        position.z       );
	glEnd();

	//glColor3d(1,1,0);
	materials["right"].draw();
	glBegin(GL_QUADS);
	glTexCoord2d(0,0); glVertex3d(position.x+size.x, position.y,        position.z+size.z);
	glTexCoord2d(0,1); glVertex3d(position.x+size.x, position.y+size.y, position.z+size.z);
	glTexCoord2d(1,1); glVertex3d(position.x+size.x, position.y+size.y, position.z       );
	glTexCoord2d(1,0); glVertex3d(position.x+size.x, position.y,        position.z       );
	glEnd();

	//glColor3d(0,1,0);
	materials["bottom"].draw();
	glBegin(GL_QUADS);
	glTexCoord2d(0,0); glVertex3d(position.x,        position.y,        position.z+size.z);
	glTexCoord2d(0,1); glVertex3d(position.x,        position.y,        position.z       );
	glTexCoord2d(1,1); glVertex3d(position.x+size.x, position.y,        position.z       );
	glTexCoord2d(1,0); glVertex3d(position.x+size.x, position.y,        position.z+size.z);
	glEnd();

	//glColor3d(0,1,1);
	materials["top"].draw();
	glBegin(GL_QUADS);
	glTexCoord2d(0,0); glVertex3d(position.x,        position.y+size.y, position.z+size.z);
	glTexCoord2d(0,1); glVertex3d(position.x,        position.y+size.y, position.z       );
	glTexCoord2d(1,1); glVertex3d(position.x+size.x, position.y+size.y, position.z       );
	glTexCoord2d(1,0); glVertex3d(position.x+size.x, position.y+size.y, position.z+size.z);
	glEnd();

	//glColor3d(0,0,1);
	materials["front"].draw();
	glBegin(GL_QUADS);
	glTexCoord2d(0,0); glVertex3d(position.x,        position.y,        position.z       );
	glTexCoord2d(0,1); glVertex3d(position.x,        position.y+size.y, position.z       );
	glTexCoord2d(1,1); glVertex3d(position.x+size.x, position.y+size.y, position.z       );
	glTexCoord2d(1,0); glVertex3d(position.x+size.x, position.y,        position.z       );
	glEnd();

	//glColor3d(1,0,1);
	materials["back"].draw();
	glBegin(GL_QUADS);
	glTexCoord2d(0,0); glVertex3d(position.x,        position.y,        position.z+size.z);
	glTexCoord2d(0,1); glVertex3d(position.x,        position.y+size.y, position.z+size.z);
	glTexCoord2d(1,1); glVertex3d(position.x+size.x, position.y+size.y, position.z+size.z);
	glTexCoord2d(1,0); glVertex3d(position.x+size.x, position.y,        position.z+size.z);
	glEnd();
}