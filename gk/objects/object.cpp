#include "object.hpp"
#include "engine.hpp"

void object::compile(const object* parent)
{
	this->parent = parent;
	root = parent->root;

	composition.reset(new transformation(*parent->composition));
	composition->translate(translation);
	composition->rotate(rotation);	
}

void object::draw() const
{
}

const material* object::bound_material(std::string name) const
{
	if (bindings.count(name))
		name = bindings.find(name)->second;
	
	else if (bindings.count("default"))
		name = bindings.find("default")->second;

	return parent->bound_material(name);
}
