#ifndef OBJECTS_BSP_ENTITY_HPP
#define OBJECTS_BSP_ENTITY_HPP

#include <string>

class bsp_entity
{
public:
	bsp_entity(std::string description);
	void draw() const;
};

#endif
