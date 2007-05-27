#include "box.hpp"
#include "world.hpp"
#include "matrix.hpp"
#include "material.hpp"
#include "state.hpp"
#include "opengl.hpp"

void box::compile(const object& parent)
{
	object::compile(parent);

	matrix offset;
	offset.translate(vertex(size.x/2, size.y/2, size.z/2));

	NewtonCollision* collision = NewtonCreateBox(root().newton(),
		size.x, size.y, size.z, offset.row_major_data());

	NewtonBody *body = NewtonCreateBody(root().newton(), collision);
	NewtonReleaseCollision(root().newton(), collision);
	
	NewtonBodySetMatrix(body, composition().row_major_data());

/*
	body::compile();

	matrix offset;
	offset.translate(vertex(size.x/2, size.y/2, size.z/2));

	NewtonCollision* collision = NewtonCreateBox(root().newton(),
		size.x, size.y, size.z, offset.row_major_data());

	NewtonBodySetCollision(newton(), collision);
	NewtonReleaseCollision(root().newton(), collision);
*/
	list.reset(new list_wrapper());

	list_scope scope(*list);
	state state;
	object::draw(state);
	draw_faces(state);
}

void box::draw(const state& state) const
{
	list->call();
}

/*
const world& box::root() const
{
	return object::root();
}

const matrix& box::composition() const
{
	return object::composition();
}
*/

void box::draw_faces(const state& state) const
{
	matrix_scope scope(composition());
	
	glPushAttrib(GL_CURRENT_BIT);

	draw_left_face(state);
	draw_right_face(state);
	draw_bottom_face(state);
	draw_top_face(state);
	draw_front_face(state);
	draw_back_face(state);

	glPopAttrib();
}

void box::draw_left_face(const state& state) const
{
	float s, t;

	const material& left = bound_material(size.x > 0 ? "left" : "right");
	material_scope scope(left);

	glNormal3f(-size.x, 0, 0);
	glBegin(GL_QUADS);
	boost::tie(s, t) = left.texture.ratio(size.z, size.y);
	glTexCoord2f(0, 0); glVertex3f(0,      0,      size.z);
	glTexCoord2f(0, t); glVertex3f(0,      size.y, size.z);
	glTexCoord2f(s, t); glVertex3f(0,      size.y, 0     );
	glTexCoord2f(s, 0); glVertex3f(0,      0,      0     );
	glEnd();
}

void box::draw_right_face(const state& state) const
{
	float s, t;

	const material& right = bound_material(size.x > 0 ? "right" : "left");
	material_scope scope(right);

	glNormal3f(size.x, 0, 0);
	glBegin(GL_QUADS);
	boost::tie(s, t) = right.texture.ratio(size.z, size.y);
	glTexCoord2f(0, 0); glVertex3f(size.x, 0,      size.z);
	glTexCoord2f(0, t); glVertex3f(size.x, size.y, size.z);
	glTexCoord2f(s, t); glVertex3f(size.x, size.y, 0     );
	glTexCoord2f(s, 0); glVertex3f(size.x, 0,      0     );
	glEnd();
}

void box::draw_bottom_face(const state& state) const
{
	float s, t;

	const material& bottom = bound_material(size.y > 0 ? "bottom" : "top");
	material_scope scope(bottom);

	glNormal3f(0, -size.y, 0);
	glBegin(GL_QUADS);
	boost::tie(s, t) = bottom.texture.ratio(size.x, size.z);
	glTexCoord2f(0, 0); glVertex3f(0,      0,      size.z);
	glTexCoord2f(0, t); glVertex3f(0,      0,      0     );
	glTexCoord2f(s, t); glVertex3f(size.x, 0,      0     );
	glTexCoord2f(s, 0); glVertex3f(size.x, 0,      size.z);
	glEnd();
}

void box::draw_top_face(const state& state) const
{
	float s, t;

	const material& top = bound_material(size.y > 0 ? "top" : "bottom");
	top.draw();

	glNormal3f(0, size.y, 0);
	glBegin(GL_QUADS);
	boost::tie(s, t) = top.texture.ratio(size.x, size.z);
	glTexCoord2f(0, 0); glVertex3f(0,      size.y, size.z);
	glTexCoord2f(0, t); glVertex3f(0,      size.y, 0     );
	glTexCoord2f(s, t); glVertex3f(size.x, size.y, 0     );
	glTexCoord2f(s, 0); glVertex3f(size.x, size.y, size.z);
	glEnd();
}

void box::draw_front_face(const state& state) const
{	
	float s, t;

	const material& front = bound_material(size.z < 0 ? "front" : "back");
	material_scope scope(front);

	glNormal3f(0, 0, -size.z);	
	glBegin(GL_QUADS);
	boost::tie(s, t) = front.texture.ratio(size.x, size.y);
	glTexCoord2f(0, 0); glVertex3f(0,      0,      0     );
	glTexCoord2f(0, t); glVertex3f(0,      size.y, 0     );
	glTexCoord2f(s, t); glVertex3f(size.x, size.y, 0     );
	glTexCoord2f(s, 0); glVertex3f(size.x, 0,      0     );
	glEnd();

	//glBegin(GL_QUADS);
	//for (int x = 0; x<=size.x*2; x++)
	//	for (int y = 0; y<=size.y*2; y++)
	//	{
	//		glVertex3f(0,      0,      0     );
	//		glVertex3f(0,      y*0.5,  0     );
	//		glVertex3f(x*0.5,  y*0.5,  0     );
	//		glVertex3f(x*0.5,  0,      0     );
	//	}
	//glEnd();
}

void box::draw_back_face(const state& state) const
{
	float s, t;

	const material& back = bound_material(size.z < 0 ? "back" : "front");
	material_scope scope(back);

	glNormal3f(0, 0, size.z);
	glBegin(GL_QUADS);
	boost::tie(s, t) = back.texture.ratio(size.x, size.y);
	glTexCoord2f(0, 0); glVertex3f(0,      0,      size.z);
	glTexCoord2f(0, t); glVertex3f(0,      size.y, size.z);
	glTexCoord2f(s, t); glVertex3f(size.x, size.y, size.z);
	glTexCoord2f(s, 0); glVertex3f(size.x, 0,      size.z);
	glEnd();

	//glBegin(GL_QUADS);
	//for (int x = 0; x<=size.x*2; x++)
	//	for (int y = 0; y<=size.y*2; y++)
	//	{
	//		glVertex3f(0,      0,      size.z);
	//		glVertex3f(0,      y*0.5,  size.z);
	//		glVertex3f(x*0.5,  y*0.5,  size.z);
	//		glVertex3f(x*0.5,  0,      size.z);
	//	}
	//glEnd();
}
