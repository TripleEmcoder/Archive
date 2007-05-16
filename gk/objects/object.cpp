#include "object.hpp"
#include "transformation.hpp"
#include "scope.hpp"
#include "engine.hpp"

void object::compile(const object& parent)
{
	this->_parent = &parent;
	_root = _parent->_root;

	_composition.reset(new transformation(*_parent->_composition));
	_composition->translate(translation);
	_composition->rotate(rotation);	
}

void object::draw() const
{
#ifdef _DEBUG
	scope local(*_composition);
	auxSolidSphere(0.1);
#endif
}

const object& object::parent() const
{
	return *_parent;
}

const world& object::root() const
{
	return *_root;
}

const transformation& object::composition() const
{
	return *_composition;
}

const material& object::bound_material(std::string name) const
{
	if (bindings.count(name))
		name = bindings.find(name)->second;
	
	else if (bindings.count("default"))
		name = bindings.find("default")->second;

	return _parent->bound_material(name);
}
