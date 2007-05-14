#include "wall.hpp"
#include "cuboid.hpp"
#include "material.hpp"

#include <algorithm>

#include <boost/lambda/lambda.hpp>
#include <boost/lambda/bind.hpp>

using boost::lambda::bind;
using boost::lambda::_1;
using boost::lambda::_2;

#include <windows.h>
#include <GL/gl.h>

void wall::draw() const
{
	glPushMatrix();
	object::draw();

	material brick("brick.tga");

	cuboid wall;
	wall.materials["front"] = brick;
	wall.materials["back"] = brick;

	std::vector<door> sorted(doors);
	sorted.push_back(door(0, 0, 0));
	sorted.push_back(door(length, 0, 0));

	std::sort(sorted.begin(), sorted.end(), 
		bind(&door::position, _1) < bind(&door::position, _2));

	for (size_t i=1; i<sorted.size(); i++)
	{
		door& previous(sorted[i-1]);
		door& current(sorted[i]);

		vertex before_position;
		before_position.x += previous.position + previous.width;

		double before_width = current.position - previous.position - previous.width;
		wall.position = before_position;
		wall.size = vertex(before_width, height, -thickness);
		wall.draw();

		vertex above_position;
		above_position.x += current.position;
		above_position.y += current.height;

		double above_height = height - current.height;
		wall.position = above_position;
		wall.size = vertex(current.width, above_height, -thickness);
		wall.draw();
	}

	glPopMatrix();
}