#include "ceiling.hpp"
#include "box.hpp"

void ceiling::compile(const object& parent)
{
	object::compile(parent);

	_body.reset(new box());
	_body->size = vertex(width, 0.2f, -depth);
	_body->compile(*this);
}

void ceiling::draw(const state& state) const
{
	object::draw(state);

	_body->draw(state);
}

const material& ceiling::bound_material(std::string name) const
{
	if (name == "bottom")
		name = "ceiling";

	return object::bound_material(name);
}
