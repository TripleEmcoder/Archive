#include "ceiling.hpp"
#include "box.hpp"
#include "engine.hpp"

void ceiling::compile(const object& parent)
{
	object::compile(parent);

	_body.reset(new box());
	_body->size = vertex(width, 0.2, -depth);
	_body->compile(*this);
}

void ceiling::draw() const
{
	_body->draw();
}

const material& ceiling::bound_material(std::string name) const
{
	if (name == "bottom")
		name = "ceiling";

	return object::bound_material(name);
}
