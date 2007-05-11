#include "fps_counter.hpp"

#define _CRT_SECURE_NO_WARNINGS

#include <GL/glut.h>
#include <cstdio>

fps_counter::fps_counter(int width, int heigth)
	:time(0), timebase(0), frame(0), width(width), heigth(heigth)
{
}

fps_counter::~fps_counter(void)
{
}

void fps_counter::setOrthographicProjection() 
{
	// switch to projection mode
	glMatrixMode(GL_PROJECTION);
	// save previous matrix which contains the 
	//settings for the perspective projection
	glPushMatrix();
	// reset matrix
	glLoadIdentity();
	// set a 2D orthographic projection
	gluOrtho2D(0, width, 0, heigth);
	// invert the y axis, down is positive
	glScalef(1, -1, 1);
	// mover the origin from the bottom left corner
	// to the upper left corner
	glTranslatef(0, -heigth, 0);
	glMatrixMode(GL_MODELVIEW);
}

void fps_counter::resetPerspectiveProjection() 
{
	// set the current matrix to GL_PROJECTION
	glMatrixMode(GL_PROJECTION);
	// restore previous settings
	glPopMatrix();
	// get back to GL_MODELVIEW matrix
	glMatrixMode(GL_MODELVIEW);
}

void fps_counter::renderBitmapString(float x, float y, void *font, char *string)
{
  
  char *c;
  // set position to start drawing fonts
  glRasterPos2f(x, y);
  // loop all the characters in the string
  for (c = string; *c != '\0'; c++) 
  {
	glutBitmapCharacter(font, *c);
  }
}

void fps_counter::draw()
{
	frame++;
	time = glutGet(GLUT_ELAPSED_TIME);
	
	if (time - timebase > 1000) 
	{
		sprintf(s, "FPS:%4.2f", frame*1000.0/(time-timebase));
		timebase = time;		
		frame = 0;
	}

	glColor3f(0.0f, 1.0f, 1.0f);
	glPushMatrix();
	glLoadIdentity();
	setOrthographicProjection();
	renderBitmapString(30, 35, GLUT_BITMAP_8_BY_13, s);
	glPopMatrix();
	resetPerspectiveProjection();
}