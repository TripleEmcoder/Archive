#pragma once

#include "HUDElement.hpp"

class FPSCounter : public HUDElement
{
private:
	char s[30];
	int frame, time, timebase;
public:
	FPSCounter();
	~FPSCounter(void);
	virtual void draw();
};
