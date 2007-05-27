#include "sphere.hpp"
#include "opengl.hpp"

void sphere::compile(const object& parent)
{
	object::compile(parent);
}

void sphere::draw(const state& state) const
{
	matrix_scope ms(composition());
	glutSolidSphere(radius, 10, 10);
}
