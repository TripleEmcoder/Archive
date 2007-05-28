#include "crosshair.hpp"
#include "opengl.hpp"

crosshair::crosshair(float size)
:
	size(size)
{
}

void crosshair::draw(const state& state) const
{
	int width = glutGet(GLUT_WINDOW_WIDTH);
	int height = glutGet(GLUT_WINDOW_HEIGHT);

	glBegin(GL_LINES);
	glVertex2f(width/2 - size, height/2);
	glVertex2f(width/2 + size, height/2);
	glVertex2f(width/2, height/2 - size);
	glVertex2f(width/2, height/2 + size);
	glEnd();
}
