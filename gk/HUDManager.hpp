#pragma once

#include "HUDElement.hpp"

#include <set>

class HUDManager
{
private:
	std::set<HUDElement*> elements;
	void setOrthographicProjection();
	void resetPerspectiveProjection();
public:
	HUDManager();
	void add(HUDElement* element);
	void remove(HUDElement* element);
	void draw();
	~HUDManager(void);
};
