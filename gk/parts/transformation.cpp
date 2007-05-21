#include "transformation.hpp"
#include "matrix.hpp"

void transformation::compile()
{
	_composition.reset(new matrix());
	
	if (name == "translation")
		_composition->translate(description);

	else if (name == "rotation")
		_composition->rotate(description);

	else if (name == "scale")
		_composition->scale(description);
}

const matrix& transformation::composition() const
{
	return *_composition;
}
