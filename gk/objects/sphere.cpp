#include "sphere.hpp"
#include "transformation.hpp"
#include "material.hpp"
#include "scope.hpp"
#include "engine.hpp"

void sphere::compile(const object& parent)
{
	object::compile(parent);
}

void sphere::draw(const state& state) const
{
	matrix_scope ms(composition());
	glutSolidSphere(radius, 10, 10);
}
