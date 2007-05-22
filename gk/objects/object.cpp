#include "object.hpp"
#include "matrix.hpp"
#include "scope.hpp"
#include "material.hpp"
#include "transformation.hpp"
#include "engine.hpp"

#include <boost/bind.hpp>

object::object()
:
	_parent(NULL), _root(NULL), _composition(new matrix())
{
}

class transformation_composer
{
public:
	transformation_composer(matrix& composition)
	:
		composition(composition)
	{
	}

	void operator()(const transformation& element)
	{
		composition.compose(element.composition());
	}

private:
	matrix& composition;
};

void object::compile(const object& parent)
{
	_parent = &parent;
	_root = _parent->_root != NULL ? _parent->_root : (world*)_parent;

	_composition.reset(new matrix());
	_composition->compose(*_parent->_composition);
	
	for_each(transformations.begin(), transformations.end(),
		boost::bind(&transformation::compile, _1));

	for_each(transformations.begin(), transformations.end(),
		transformation_composer(*_composition));
}

void object::draw(const state& state) const
{
#ifdef _DEBUG
	matrix_scope ms(*_composition);
	bound_material("debug").draw(state);
	glutSolidSphere(0.1, 20, 20);
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

const matrix& object::composition() const
{
	return *_composition;
}

matrix& object::composition()
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
