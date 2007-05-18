#include "builtin.hpp"
#include "scope.hpp"
#include "material.hpp"
#include "engine.hpp"

void builtin::compile(const object& parent)
{
	object::compile(parent);
}

void builtin::draw() const
{
	object::draw();

	scope local(composition());

	bound_material("teapot").draw();
	auxSolidTeapot(0.5);
}
