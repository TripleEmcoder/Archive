#include "ground.hpp"
#include "cuboid.hpp"
#include "engine.hpp"

void ground::compile(const object* parent)
{
	object::compile(parent);

	body.reset(new cuboid());
	body->size = vertex(width, -0.2, -depth);
	body->compile(this);
}

void ground::draw() const
{
	body->draw();
}

const material* ground::bound_material(std::string name) const
{
	if (name == "top")
		name = "ground";

	return object::bound_material(name);
}
