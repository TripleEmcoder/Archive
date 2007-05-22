#include "ground.hpp"
#include "box.hpp"

void ground::compile(const object& parent)
{
	object::compile(parent);

	_body.reset(new box());
	_body->size = vertex(width, -0.2f, -depth);
	_body->compile(*this);
}

void ground::draw(const state& state) const
{
	object::draw(state);

	_body->draw(state);
}

const material& ground::bound_material(std::string name) const
{
	if (name == "top")
		name = "ground";

	return object::bound_material(name);
}
