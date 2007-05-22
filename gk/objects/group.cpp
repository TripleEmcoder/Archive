#include "group.hpp"
#include "transformation.hpp"

#include <algorithm>

#include <boost/bind.hpp>

using boost::ref;
using boost::bind;

void group::compile(const object& parent)
{
	object::compile(parent);

	if (visible)
	{
		std::for_each(builtins.begin(), builtins.end(), bind(&object::compile, _1, ref(*this)));
		std::for_each(grounds.begin(), grounds.end(), bind(&object::compile, _1, ref(*this)));
		std::for_each(ceilings.begin(), ceilings.end(), bind(&object::compile, _1, ref(*this)));
		std::for_each(walls.begin(), walls.end(), bind(&object::compile, _1, ref(*this)));
		std::for_each(bsps.begin(), bsps.end(), bind(&object::compile, _1, ref(*this)));
		std::for_each(groups.begin(), groups.end(), bind(&object::compile, _1, ref(*this)));
	}
}

void group::draw(const state& state) const
{
	object::draw(state);

	if (visible)
	{
		std::for_each(builtins.begin(), builtins.end(), bind(&object::draw, _1, ref(state)));
		std::for_each(grounds.begin(), grounds.end(), bind(&object::draw, _1, ref(state)));
		std::for_each(ceilings.begin(), ceilings.end(), bind(&object::draw, _1, ref(state)));
		std::for_each(walls.begin(), walls.end(), bind(&object::draw, _1, ref(state)));
		std::for_each(bsps.begin(), bsps.end(), bind(&object::draw, _1, ref(state)));
		std::for_each(groups.begin(), groups.end(), bind(&object::draw, _1, ref(state)));
	}
}
