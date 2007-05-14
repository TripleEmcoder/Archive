#include "Crosshair.hpp"

#include <GL/glut.h>

Crosshair::Crosshair(float colorRed, float colorGreen, float colorBlue, float size)
	:red(colorRed), green(colorGreen), blue(colorBlue), size(size)
{
}

Crosshair::~Crosshair(void)
{
}

void Crosshair::drawHUD()
{
	int width = glutGet(GLUT_WINDOW_WIDTH);
	int height = glutGet(GLUT_WINDOW_HEIGHT);
	glColor3f(red, green, blue);
	glBegin(GL_LINES);
	glVertex2f(width/2 - size, height/2);
	glVertex2f(width/2 + size, height/2);
	glVertex2f(width/2, height/2 - size);
	glVertex2f(width/2, height/2 + size);
	glEnd();
}
