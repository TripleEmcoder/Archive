#include "wall.hpp"
#include "box.hpp"

void wall::compile(const object& parent)
{
	object::compile(parent);

	_body.reset(new box());
	_body->size = vertex(length, height, -0.2f);
	_body->compile(*this);
}

void wall::draw(const state& state) const
{
	object::draw(state);

	_body->draw(state);
}

const material& wall::bound_material(std::string name) const
{
	if (name == "front" || name == "back")
		name = "wall";

	return object::bound_material(name);
}
