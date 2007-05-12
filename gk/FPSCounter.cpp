#include "FPSCounter.hpp"

#define _CRT_SECURE_NO_WARNINGS

#include <cstdio>
#include <GL/glut.h>

FPSCounter::FPSCounter()
	:time(0), timebase(0), frame(0)
{
	s[0] = '\0';
}

FPSCounter::~FPSCounter(void)
{
}



void FPSCounter::draw()
{
	frame++;
	time = glutGet(GLUT_ELAPSED_TIME);
	
	if (time - timebase > 1000) 
	{
		sprintf(s, "FPS:%4.2f", frame*1000.0/(time-timebase));
		timebase = time;		
		frame = 0;
	}

	renderBitmapString(30, 35, GLUT_BITMAP_8_BY_13, s);
}