#include "group.hpp"

#include <algorithm>
#include <functional>

void group::draw() const
{
	if (visible)
	{
		std::for_each(quads.begin(), quads.end(), std::mem_fun_ref(&quad::draw));
		std::for_each(cuboids.begin(), cuboids.end(), std::mem_fun_ref(&cuboid::draw));
		std::for_each(staircases.begin(), staircases.end(), std::mem_fun_ref(&staircase::draw));
		std::for_each(walls.begin(), walls.end(), std::mem_fun_ref(&wall::draw));
		std::for_each(groups.begin(), groups.end(), std::mem_fun_ref(&group::draw));
	}
}
