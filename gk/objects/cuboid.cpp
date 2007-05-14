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

	glPushMatrix();
	object::draw();

	//glColor3d(1,0,0);
	materials["left"].draw();
	glBegin(GL_QUADS);
	glTexCoord2d(0,0); glVertex3d(0,      0,      size.z);
	glTexCoord2d(0,1); glVertex3d(0,      size.y, size.z);
	glTexCoord2d(1,1); glVertex3d(0,      size.y, 0     );
	glTexCoord2d(1,0); glVertex3d(0,      0,      0     );
	glEnd();

	//glColor3d(1,1,0);
	materials["right"].draw();
	glBegin(GL_QUADS);
	glTexCoord2d(0,0); glVertex3d(size.x, 0,      size.z);
	glTexCoord2d(0,1); glVertex3d(size.x, size.y, size.z);
	glTexCoord2d(1,1); glVertex3d(size.x, size.y, 0     );
	glTexCoord2d(1,0); glVertex3d(size.x, 0,      0     );
	glEnd();

	//glColor3d(0,1,0);
	materials["bottom"].draw();
	glBegin(GL_QUADS);
	glTexCoord2d(0,0); glVertex3d(0,      0,      size.z);
	glTexCoord2d(0,1); glVertex3d(0,      0,      0     );
	glTexCoord2d(1,1); glVertex3d(size.x, 0,      0     );
	glTexCoord2d(1,0); glVertex3d(size.x, 0,      size.z);
	glEnd();

	//glColor3d(0,1,1);
	materials["top"].draw();
	glBegin(GL_QUADS);
	glTexCoord2d(0,0); glVertex3d(0,      size.y, size.z);
	glTexCoord2d(0,1); glVertex3d(0,      size.y, 0     );
	glTexCoord2d(1,1); glVertex3d(size.x, size.y, 0     );
	glTexCoord2d(1,0); glVertex3d(size.x, size.y, size.z);
	glEnd();

	//glColor3d(0,0,1);
	materials["front"].draw();
	glBegin(GL_QUADS);
	glTexCoord2d(0,0); glVertex3d(0,      0,      0     );
	glTexCoord2d(0,1); glVertex3d(0,      size.y, 0     );
	glTexCoord2d(1,1); glVertex3d(size.x, size.y, 0     );
	glTexCoord2d(1,0); glVertex3d(size.x, 0,      0     );
	glEnd();

	//glColor3d(1,0,1);
	materials["back"].draw();
	glBegin(GL_QUADS);
	glTexCoord2d(0,0); glVertex3d(0,      0,      size.z);
	glTexCoord2d(0,1); glVertex3d(0,      size.y, size.z);
	glTexCoord2d(1,1); glVertex3d(size.x, size.y, size.z);
	glTexCoord2d(1,0); glVertex3d(size.x, 0,      size.z);
	glEnd();

	glPopMatrix();
}

void cuboid::build(NewtonCollision* collision) const
{
	dFloat front[4][3] =  {
		{0, 0, 0},
		{0, size.y, 0},
		{size.x, size.y, 0},
		{size.x, 0, 0}
	};
	NewtonTreeCollisionAddFace(collision, 4, (dFloat*)front, sizeof(front[0]), 1);

	dFloat back[4][3] =  {
		{0, 0, size.z},
		{0, size.y, size.z},
		{size.x, size.y, size.z},
		{size.x, 0, size.z}
	};
	NewtonTreeCollisionAddFace(collision, 4, (dFloat*)back, sizeof(back[0]), 1);
}
