#pragma once

#include "HUDElement.hpp"

class FPSCounter : public HUDElement
{
private:
	double fps;
	int frame, time, timebase;
public:
	FPSCounter();
	~FPSCounter(void);
	virtual void drawHUD();
};
