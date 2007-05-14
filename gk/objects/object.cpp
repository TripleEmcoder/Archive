#include "object.hpp"
#include "engine.hpp"

object::object()
{
}

object::object(vertex position)
: position(position)
{
}

/*
const material& object::material(const object& parent, std::string name)
{
	return parent.material(materials[name]);
}
*/

void object::draw() const
{
	glTranslated(position.x, position.y, position.z);
	glRotated(rotation.x, 1, 0, 0);
	glRotated(rotation.y, 0, 1, 0);
	glRotated(rotation.z, 0, 0, 1);
}

void object::compile(const object* parent)
{
	this->parent = parent;
	root = parent->root;
}

const material* object::resolve(std::string name) const
{
	if (bindings.count(name))
		name = bindings.find(name)->second;
	
	else if (bindings.count("default"))
		name = bindings.find("default")->second;

	return parent->resolve(name);
}
