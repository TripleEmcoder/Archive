#include "cuboid.hpp"
#include "material.hpp"
#include "world.hpp"
#include "engine.hpp"
#include "../math.hpp"

cuboid::cuboid()
{
}

cuboid::cuboid(vertex position, vertex size)
: object(position), size(size)
{
}

void cuboid::draw() const
{
	glPushMatrix();
	object::draw();

	float s, t;
	
	const material* left = resolve("left");
	left->draw();

	glBegin(GL_QUADS);
	boost::tie(s, t) = left->texture.ratio(size.z, size.y);
	glTexCoord2d(0, 0); glVertex3d(0,      0,      size.z);
	glTexCoord2d(0, t); glVertex3d(0,      size.y, size.z);
	glTexCoord2d(s, t); glVertex3d(0,      size.y, 0     );
	glTexCoord2d(s, 0); glVertex3d(0,      0,      0     );
	glEnd();

	const material* right = resolve("right");
	right->draw();

	glBegin(GL_QUADS);
	boost::tie(s, t) = right->texture.ratio(size.z, size.y);
	glTexCoord2d(0, 0); glVertex3d(size.x, 0,      size.z);
	glTexCoord2d(0, t); glVertex3d(size.x, size.y, size.z);
	glTexCoord2d(s, t); glVertex3d(size.x, size.y, 0     );
	glTexCoord2d(s, 0); glVertex3d(size.x, 0,      0     );
	glEnd();

	//glColor3d(0,1,0);
	const material* bottom = resolve("bottom");
	bottom->draw();

	glBegin(GL_QUADS);
	boost::tie(s, t) = bottom->texture.ratio(size.x, size.z);
	glTexCoord2d(0, 0); glVertex3d(0,      0,      size.z);
	glTexCoord2d(0, t); glVertex3d(0,      0,      0     );
	glTexCoord2d(s, t); glVertex3d(size.x, 0,      0     );
	glTexCoord2d(s, 0); glVertex3d(size.x, 0,      size.z);
	glEnd();

	const material* top = resolve("top");
	top->draw();

	glBegin(GL_QUADS);
	boost::tie(s, t) = top->texture.ratio(size.x, size.z);
	glTexCoord2d(0, 0); glVertex3d(0,      size.y, size.z);
	glTexCoord2d(0, t); glVertex3d(0,      size.y, 0     );
	glTexCoord2d(s, t); glVertex3d(size.x, size.y, 0     );
	glTexCoord2d(s, 0); glVertex3d(size.x, size.y, size.z);
	glEnd();

	const material* front = resolve("front");
	front->draw();

	glBegin(GL_QUADS);
	boost::tie(s, t) = front->texture.ratio(size.x, size.y);
	glTexCoord2d(0, 0); glVertex3d(0,      0,      0     );
	glTexCoord2d(0, t); glVertex3d(0,      size.y, 0     );
	glTexCoord2d(s, t); glVertex3d(size.x, size.y, 0     );
	glTexCoord2d(s, 0); glVertex3d(size.x, 0,      0     );
	glEnd();

	const material* back = resolve("back");
	back->draw();

	glBegin(GL_QUADS);
	boost::tie(s, t) = back->texture.ratio(size.x, size.y);
	glTexCoord2d(0, 0); glVertex3d(0,      0,      size.z);
	glTexCoord2d(0, t); glVertex3d(0,      size.y, size.z);
	glTexCoord2d(s, t); glVertex3d(size.x, size.y, size.z);
	glTexCoord2d(s, 0); glVertex3d(size.x, 0,      size.z);
	glEnd();

	glPopMatrix();
}

void cuboid::compile(const object* parent)
{
	object::compile(parent);

	NewtonCollision* collision = NewtonCreateBox(root->newton.get(), size.x+2, size.y+2, size.z+2, NULL);
	NewtonBody* body = NewtonCreateBody(root->newton.get(), collision);
	NewtonReleaseCollision(root->newton.get(), collision);

	Matrix location = identity_matrix<float>(4);

	matrix_row<Matrix> row(location, 3);
	row[0] = position.x+size.x/2;
	row[1] = position.y+size.y/2;
	row[2] = position.z+size.z/2;

	// set the global position of this body
	NewtonBodySetMatrix(body, location.data());

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
