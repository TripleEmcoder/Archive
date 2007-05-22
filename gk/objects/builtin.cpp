#include "builtin.hpp"
#include "scope.hpp"
#include "material.hpp"
#include "engine.hpp"

void builtin::compile(const object& parent)
{
	object::compile(parent);
}

void builtin::draw(const state& state) const
{
	object::draw(state);

	matrix_scope ms(composition());
	material_scope(bound_material(name));
	
	if (name == "sphere")
		glutSolidSphere(0.5, 20, 20);	

	else if (name =="teapot")
		glutSolidTeapot(0.5);
	
	_ASSERTE(glGetError() == GL_NO_ERROR);
}
