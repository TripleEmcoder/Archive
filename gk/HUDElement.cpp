#include "HUDElement.hpp"

#define _CRT_SECURE_NO_WARNINGS

#include <GL/glut.h>
#include <cstdarg>
#include <cstring>
#include <cstdio>

void HUDElement::renderBitmapString(float x, float y, const char *fmt, ... )
{
	char string[1024];
	
	va_list argptr;
	
	va_start(argptr, fmt);
	vsprintf(string, fmt, argptr);
	va_end(argptr);

	glRasterPos3f(x, y, 0);
	int len = (int) strlen(string);
	for (int i = 0; i < len; i++) 
	{
		glutBitmapCharacter(GLUT_BITMAP_8_BY_13, string[i]);
	}
}

HUDElement::~HUDElement(void)
{
}
