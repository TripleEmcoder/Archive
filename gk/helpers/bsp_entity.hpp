#ifndef HELPERS_BSP_ENTITY_HPP
#define HELPERS_BSP_ENTITY_HPP

#include <string>
#include <vector>

#include "bsp_common.hpp"

class bsp_entity
{
public:
	static std::vector<std::string> split(std::string entities);

	bsp_entity(std::string description);
	void draw() const;

private:
	bsp_vector3f origin;
	float angle;
};

#endif //HELPERS_BSP_ENTITY_HPP
