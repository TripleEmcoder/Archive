#include "wall.hpp"
#include "cuboid.hpp"

#include <algorithm>

#include <boost/lambda/lambda.hpp>
#include <boost/lambda/bind.hpp>

	
using boost::lambda::bind;
using boost::lambda::_1;
using boost::lambda::_2;

void wall::draw() const
{
	std::vector<door> sorted(doors);
	sorted.push_back(door(0, 0, 0));
	sorted.push_back(door(length, 0, 0));

	std::sort(sorted.begin(), sorted.end(), 
		bind(&door::position, _1) < bind(&door::position, _2));

	for (int i=1; i<sorted.size(); i++)
	{
		door& previous(sorted[i-1]);
		door& current(sorted[i]);

		vertex before_position(position);
		before_position.x += previous.position + previous.width;

		double before_width = current.position - previous.position - previous.width;
		cuboid before(before_position, vertex(before_width, height, -thickness));
		before.draw();

		vertex above_position(position);
		above_position.x += current.position;
		above_position.y += current.height;

		double above_height = height - current.height;
		cuboid above(above_position, vertex(current.width, above_height, -thickness));
		above.draw();
	}
}