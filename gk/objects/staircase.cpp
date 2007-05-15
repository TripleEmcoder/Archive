#include "staircase.hpp"
#include "cuboid.hpp"
#include "engine.hpp"

void staircase::compile(const object* parent)
{
	object::compile(parent);
}

/*
void staircase::stair::draw() const
{
	float height(height-thickness);
	float depth(depth+thickness+overhang);

	cuboid vertical(translation, vertex(width, height, -thickness));
	vertical.draw(map);

	cuboid horizontal(translation+vertex(0, height, overhang), vertex(width, thickness, -depth));
	horizontal.draw(map);
}
*/

void staircase::draw() const
{
	/*
	glPushMatrix();
	object::draw();

	stair instance(model);

	for (size_t i=0; i<count; i++)
	{
		instance.translation.y = 0 + i*model.height;
		instance.translation.z = 0 - i*model.depth;

		instance.draw(map);
	}

	glPopMatrix();
	*/
}
