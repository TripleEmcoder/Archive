#include "wall.hpp"
#include "box.hpp"
#include "engine.hpp"

#include <algorithm>

#include <boost/lambda/lambda.hpp>
#include <boost/lambda/bind.hpp>

using boost::lambda::bind;
using boost::lambda::_1;
using boost::lambda::_2;

wall::door::door()
{
}

wall::door::door(float offset, float width, float height) 
: offset(offset), width(width), height(height)
{
}

void wall::compile(const object& parent)
{
	object::compile(parent);
}

void wall::draw() const
{
	/*
	glPushMatrix();
	object::draw();

	//material brick("brick.tga");

	box wall;
	//wall.materials["front"] = brick;
	//wall.materials["back"] = brick;

	std::vector<door> sorted(doors);
	sorted.push_back(door(0, 0, 0));
	sorted.push_back(door(length, 0, 0));

	std::sort(sorted.begin(), sorted.end(), 
		bind(&door::translation, _1) < bind(&door::translation, _2));

	for (size_t i=1; i<sorted.size(); i++)
	{
		door& previous(sorted[i-1]);
		door& current(sorted[i]);

		vertex before_translation;
		before_translation.x += previous.translation + previous.width;

		float before_width = current.translation - previous.translation - previous.width;
		wall.translation = before_translation;
		wall.size = vertex(before_width, height, -thickness);
		wall.draw(map);

		vertex above_translation;
		above_translation.x += current.translation;
		above_translation.y += current.height;

		float above_height = height - current.height;
		wall.translation = above_translation;
		wall.size = vertex(current.width, above_height, -thickness);
		wall.draw(map);
	}

	glPopMatrix();
	*/
}
