#include "staircase.hpp"
#include "engine.hpp"

void staircase::draw() const
{
	/*
	glPushMatrix();
	object::draw();

	stair instance(model);

	for (size_t i=0; i<count; i++)
	{
		instance.position.y = 0 + i*model.height;
		instance.position.z = 0 - i*model.depth;

		instance.draw(map);
	}

	glPopMatrix();
	*/
}

void staircase::compile(const object* parent)
{
	object::compile(parent);
}