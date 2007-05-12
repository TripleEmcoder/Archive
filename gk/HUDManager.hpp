#pragma once

#include "HUDElement.hpp"

#include <set>

class HUDManager
{
private:
	int heigth, width;
	std::set<HUDElement*> elements;
	void setOrthographicProjection();
	void resetPerspectiveProjection();
public:
	HUDManager(int width, int heigth);
	void add(HUDElement* element);
	void remove(HUDElement* element);
	void draw();
	~HUDManager(void);
};
