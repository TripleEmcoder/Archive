#include "cuboid.hpp"
#include "material.hpp"
#include "scope.hpp"
#include "world.hpp"
#include "engine.hpp"

void cuboid::compile(const object* parent)
{
	object::compile(parent);

	transformation offset;
	offset.translate(vertex(size.x/2, size.y/2, size.z/2));
	NewtonCollision* collision = NewtonCreateBox(root->newton.get(), size.x, size.y, size.z, offset.row_major_data());
	NewtonBody* body = NewtonCreateBody(root->newton.get(), collision);
	NewtonReleaseCollision(root->newton.get(), collision);

	transformation local(*composition);
	//local.translate(vertex(size.x/2, size.y/2, size.z/2));
	NewtonBodySetMatrix(body, local.row_major_data());

	/*
	float left[4][3] =
	{
		{0,      0,      size.z},
		{0,      size.y, size.z},
		{0,      size.y, 0     },
		{0,      0,      0     }
	};

	NewtonTreeCollisionAddFace(collision,
		sizeof(left)/sizeof(left[0]), (float*)left, sizeof(left[0]), 1);

	float right[4][3] =
	{
		{size.x, 0,      size.z},
		{size.x, size.y, size.z},
		{size.x, size.y, 0     },
		{size.x, 0,      0     },
	};

	NewtonTreeCollisionAddFace(collision,
		sizeof(right)/sizeof(right[0]), (float*)right, sizeof(right[0]), 1);

	float bottom[4][3] =
	{
		{0,      0,      size.z},
		{0,      0,      0     },
		{size.x, 0,      0     },
		{size.x, 0,      size.z}
	};

	NewtonTreeCollisionAddFace(collision,
		sizeof(bottom)/sizeof(bottom[0]), (float*)bottom, sizeof(bottom[0]), 1);

	float top[4][3] =
	{
		{0,      size.y, size.z},
		{0,      size.y, 0     },
		{size.x, size.y, 0     },
		{size.x, size.y, size.z}
	};

	NewtonTreeCollisionAddFace(collision,
		sizeof(top)/sizeof(top[0]), (float*)top, sizeof(top[0]), 1);

	float front[4][3] =
	{
		{0,      0,      0     },
		{0,      size.y, 0     },
		{size.x, size.y, 0     },
		{size.x, 0,      0     }
	};

	NewtonTreeCollisionAddFace(collision,
		sizeof(front)/sizeof(front[0]), (float*)front, sizeof(front[0]), 1);

	float back[4][3] = 
	{
		{0,      0,      size.z},
		{0,      size.y, size.z},
		{size.x, size.y, size.z},
		{size.x, 0,      size.z}
	};
	NewtonTreeCollisionAddFace(collision,
		sizeof(back)/sizeof(back[0]), (float*)back, sizeof(back[0]), 1);
	*/
}

void cuboid::draw() const
{
	scope local(*this);

	float s, t;
	
	const material* left = bound_material(size.x > 0 ? "left" : "right");
	left->draw();

	glBegin(GL_QUADS);
	boost::tie(s, t) = left->texture.ratio(size.z, size.y);
	glTexCoord2d(0, 0); glVertex3d(0,      0,      size.z);
	glTexCoord2d(0, t); glVertex3d(0,      size.y, size.z);
	glTexCoord2d(s, t); glVertex3d(0,      size.y, 0     );
	glTexCoord2d(s, 0); glVertex3d(0,      0,      0     );
	glEnd();

	const material* right = bound_material(size.x > 0 ? "right" : "left");
	right->draw();

	glBegin(GL_QUADS);
	boost::tie(s, t) = right->texture.ratio(size.z, size.y);
	glTexCoord2d(0, 0); glVertex3d(size.x, 0,      size.z);
	glTexCoord2d(0, t); glVertex3d(size.x, size.y, size.z);
	glTexCoord2d(s, t); glVertex3d(size.x, size.y, 0     );
	glTexCoord2d(s, 0); glVertex3d(size.x, 0,      0     );
	glEnd();

	//glColor3d(0,1,0);
	const material* bottom = bound_material(size.y > 0 ? "bottom" : "top");
	bottom->draw();

	glBegin(GL_QUADS);
	boost::tie(s, t) = bottom->texture.ratio(size.x, size.z);
	glTexCoord2d(0, 0); glVertex3d(0,      0,      size.z);
	glTexCoord2d(0, t); glVertex3d(0,      0,      0     );
	glTexCoord2d(s, t); glVertex3d(size.x, 0,      0     );
	glTexCoord2d(s, 0); glVertex3d(size.x, 0,      size.z);
	glEnd();

	const material* top = bound_material(size.y > 0 ? "top" : "bottom");
	top->draw();

	glBegin(GL_QUADS);
	boost::tie(s, t) = top->texture.ratio(size.x, size.z);
	glTexCoord2d(0, 0); glVertex3d(0,      size.y, size.z);
	glTexCoord2d(0, t); glVertex3d(0,      size.y, 0     );
	glTexCoord2d(s, t); glVertex3d(size.x, size.y, 0     );
	glTexCoord2d(s, 0); glVertex3d(size.x, size.y, size.z);
	glEnd();

	const material* front = bound_material(size.z > 0 ? "back" : "front");
	front->draw();

	glBegin(GL_QUADS);
	boost::tie(s, t) = front->texture.ratio(size.x, size.y);
	glTexCoord2d(0, 0); glVertex3d(0,      0,      0     );
	glTexCoord2d(0, t); glVertex3d(0,      size.y, 0     );
	glTexCoord2d(s, t); glVertex3d(size.x, size.y, 0     );
	glTexCoord2d(s, 0); glVertex3d(size.x, 0,      0     );
	glEnd();

	const material* back = bound_material(size.z > 0 ? "front" : "back");
	back->draw();

	glBegin(GL_QUADS);
	boost::tie(s, t) = back->texture.ratio(size.x, size.y);
	glTexCoord2d(0, 0); glVertex3d(0,      0,      size.z);
	glTexCoord2d(0, t); glVertex3d(0,      size.y, size.z);
	glTexCoord2d(s, t); glVertex3d(size.x, size.y, size.z);
	glTexCoord2d(s, 0); glVertex3d(size.x, 0,      size.z);
	glEnd();
}
