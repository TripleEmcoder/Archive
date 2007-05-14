#pragma once
#include "hudelement.hpp"

class Crosshair : public HUDElement
{
	float red, green, blue, size;
public:
	Crosshair(float colorRed, float colorGreen, float colorBlue, float size);
	~Crosshair(void);
	void drawHUD();
};
