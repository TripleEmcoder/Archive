#include "bsp_entity.hpp"

#include <iostream>

bsp_entity::bsp_entity(std::string description)
{
	std::cerr << description << std::endl;
}

void bsp_entity::draw() const
{
}
