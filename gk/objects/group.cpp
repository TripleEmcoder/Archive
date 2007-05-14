#include "group.hpp"

#include <algorithm>

#include <boost/lambda/lambda.hpp>
#include <boost/lambda/bind.hpp>

using boost::lambda::bind;
using boost::lambda::_1;

void group::draw() const
{
	if (visible)
	{
		std::for_each(cuboids.begin(), cuboids.end(), bind(&object::draw, _1));
		std::for_each(staircases.begin(), staircases.end(), bind(&object::draw, _1));
		std::for_each(walls.begin(), walls.end(), bind(&object::draw, _1));
		std::for_each(groups.begin(), groups.end(), bind(&object::draw, _1));
	}
}

void group::compile(const object* parent)
{
	object::compile(parent);

	if (visible)
	{
		std::for_each(cuboids.begin(), cuboids.end(), bind(&object::compile, _1, this));
		std::for_each(staircases.begin(), staircases.end(), bind(&object::compile, _1, this));
		std::for_each(walls.begin(), walls.end(), bind(&object::compile, _1, this));
		std::for_each(groups.begin(), groups.end(), bind(&object::compile, _1, this));
	}
}
