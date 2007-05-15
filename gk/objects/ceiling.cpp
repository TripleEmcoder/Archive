#include "ceiling.hpp"
#include "cuboid.hpp"
#include "engine.hpp"

void ceiling::compile(const object* parent)
{
	object::compile(parent);

	body.reset(new cuboid());
	body->size = vertex(width, 0.2, -depth);
	body->compile(this);
}

void ceiling::draw() const
{
	body->draw();
}
