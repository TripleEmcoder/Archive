#include "character.hpp"
#include "box.hpp"
#include "sphere.hpp"

void character::compile(const object& parent)
{
	object::compile(parent);

	//_body.reset(new box());
	//_body->translation = vertex(0, -size.x-0.1f, 0);
	//_body->size = vertex(size.x/10, 0.05f, size.z/10);
	//_body->compile(*this);
	//
	//_head.reset(new sphere());
	//_head->radius = size.x;
	//_head->compile(*this);
}

void character::draw() const
{
	object::draw();

	//_body->draw();
	/*_head->draw();*/
}
