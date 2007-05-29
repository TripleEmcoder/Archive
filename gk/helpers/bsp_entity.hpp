#ifndef OBJECTS_BSP_ENTITY_HPP
#define OBJECTS_BSP_ENTITY_HPP

#include <string>
#include <vector>

class bsp_entity
{
public:
	static std::vector<std::string> split(std::string entities);

	bsp_entity(std::string description);
	void draw() const;
};

#endif
