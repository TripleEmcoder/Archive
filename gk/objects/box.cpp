#include "box.hpp"
#include "world.hpp"
#include "transformation.hpp"
#include "material.hpp"
#include "scope.hpp"
#include "engine.hpp"

void box::compile(const object& parent)
{
	object::compile(parent);
	body::compile();

	transformation offset;
	offset.translate(vertex(size.x/2, size.y/2, size.z/2));

	NewtonCollision* collision = NewtonCreateBox(root().newton(),
		size.x, size.y, size.z, offset.row_major_data());

	NewtonBodySetCollision(newton(), collision);
	NewtonReleaseCollision(root().newton(), collision);
}

void box::draw() const
{
	object::draw();

	scope local(composition());

	float s, t;
	
	const material& left = bound_material(size.x > 0 ? "left" : "right");
	left.draw();

	glBegin(GL_QUADS);
	boost::tie(s, t) = left.texture.ratio(size.z, size.y);
	glTexCoord2d(0, 0); glVertex3d(0,      0,      size.z);
	glTexCoord2d(0, t); glVertex3d(0,      size.y, size.z);
	glTexCoord2d(s, t); glVertex3d(0,      size.y, 0     );
	glTexCoord2d(s, 0); glVertex3d(0,      0,      0     );
	glEnd();

	const material& right = bound_material(size.x > 0 ? "right" : "left");
	right.draw();

	glBegin(GL_QUADS);
	boost::tie(s, t) = right.texture.ratio(size.z, size.y);
	glTexCoord2d(0, 0); glVertex3d(size.x, 0,      size.z);
	glTexCoord2d(0, t); glVertex3d(size.x, size.y, size.z);
	glTexCoord2d(s, t); glVertex3d(size.x, size.y, 0     );
	glTexCoord2d(s, 0); glVertex3d(size.x, 0,      0     );
	glEnd();

	//glColor3d(0,1,0);
	const material& bottom = bound_material(size.y > 0 ? "bottom" : "top");
	bottom.draw();

	glBegin(GL_QUADS);
	boost::tie(s, t) = bottom.texture.ratio(size.x, size.z);
	glTexCoord2d(0, 0); glVertex3d(0,      0,      size.z);
	glTexCoord2d(0, t); glVertex3d(0,      0,      0     );
	glTexCoord2d(s, t); glVertex3d(size.x, 0,      0     );
	glTexCoord2d(s, 0); glVertex3d(size.x, 0,      size.z);
	glEnd();

	const material& top = bound_material(size.y > 0 ? "top" : "bottom");
	top.draw();

	glBegin(GL_QUADS);
	boost::tie(s, t) = top.texture.ratio(size.x, size.z);
	glTexCoord2d(0, 0); glVertex3d(0,      size.y, size.z);
	glTexCoord2d(0, t); glVertex3d(0,      size.y, 0     );
	glTexCoord2d(s, t); glVertex3d(size.x, size.y, 0     );
	glTexCoord2d(s, 0); glVertex3d(size.x, size.y, size.z);
	glEnd();

	const material& front = bound_material(size.z < 0 ? "front" : "back");
	front.draw();


	glBegin(GL_POINTS);
	boost::tie(s, t) = front.texture.ratio(size.x, size.y);
	for (int x = 0; x<=size.x; x++)
		for (int y = 0; y<=size.y; y++)
		{
			glVertex3d(x,     y,      0);
		}
	glEnd();;
	
	glBegin(GL_QUADS);
	//glTexCoord2d(0, 0); glVertex3d(0,      0,      0     );
	//glTexCoord2d(0, t); glVertex3d(0,      size.y, 0     );
	//glTexCoord2d(s, t); glVertex3d(size.x, size.y, 0     );
	//glTexCoord2d(s, 0); glVertex3d(size.x, 0,      0     );
	glEnd();

	const material& back = bound_material(size.z < 0 ? "back" : "front");
	back.draw();

	glBegin(GL_QUADS);
	boost::tie(s, t) = back.texture.ratio(size.x, size.y);
	glTexCoord2d(0, 0); glVertex3d(0,      0,      size.z);
	glTexCoord2d(0, t); glVertex3d(0,      size.y, size.z);
	glTexCoord2d(s, t); glVertex3d(size.x, size.y, size.z);
	glTexCoord2d(s, 0); glVertex3d(size.x, 0,      size.z);
	glEnd();
}

const world& box::root() const
{
	return object::root();
}

const transformation& box::composition() const
{
	return object::composition();
}
