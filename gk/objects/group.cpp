#include "group.hpp"

#include <algorithm>

#include <boost/lambda/lambda.hpp>
#include <boost/lambda/bind.hpp>

using boost::ref;
using boost::lambda::bind;
using boost::lambda::_1;

void group::compile(const object& parent)
{
	object::compile(parent);

	if (visible)
	{
		std::for_each(grounds.begin(), grounds.end(), bind(&object::compile, _1, ref(*this)));
		std::for_each(ceilings.begin(), ceilings.end(), bind(&object::compile, _1, ref(*this)));
		std::for_each(walls.begin(), walls.end(), bind(&object::compile, _1, ref(*this)));
		std::for_each(groups.begin(), groups.end(), bind(&object::compile, _1, ref(*this)));
	}
}

void group::draw() const
{
	object::draw();

	if (visible)
	{
		std::for_each(grounds.begin(), grounds.end(), bind(&object::draw, _1));
		std::for_each(ceilings.begin(), ceilings.end(), bind(&object::draw, _1));
		std::for_each(walls.begin(), walls.end(), bind(&object::draw, _1));
		std::for_each(groups.begin(), groups.end(), bind(&object::draw, _1));
	}
}
