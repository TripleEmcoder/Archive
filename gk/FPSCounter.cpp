#include "FPSCounter.hpp"

#define _CRT_SECURE_NO_WARNINGS

#include <GL/glut.h>

FPSCounter::FPSCounter()
	:time(0), timebase(0), frame(0), fps(0)
{
}

FPSCounter::~FPSCounter(void)
{
}



void FPSCounter::drawHUD()
{
	frame++;
	time = glutGet(GLUT_ELAPSED_TIME);
	
	if (time - timebase > 1000) 
	{
		fps = frame*1000.0/(time-timebase);
		timebase = time;		
		frame = 0;
	}

	renderBitmapString(30, 35, 0.0f, 1.0f, 1.0f, "FPS:%6.2f", fps);
}