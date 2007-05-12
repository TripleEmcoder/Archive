#include "HUDManager.hpp"

#include <GL/glut.h>
#include <algorithm>
#include <functional>

void HUDManager::setOrthographicProjection() 
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

void HUDManager::resetPerspectiveProjection() 
{
	// set the current matrix to GL_PROJECTION
	glMatrixMode(GL_PROJECTION);
	// restore previous settings
	glPopMatrix();
	// get back to GL_MODELVIEW matrix
	glMatrixMode(GL_MODELVIEW);
}

void HUDManager::draw()
{
	glColor3f(0.0f, 1.0f, 1.0f);
	glPushMatrix();
	glLoadIdentity();
	setOrthographicProjection();

	for_each(elements.begin(), elements.end(), std::mem_fun(&HUDElement::draw));
	
	glPopMatrix();
	resetPerspectiveProjection();
}

void HUDManager::add(HUDElement* element)
{
	elements.insert(element);
}
void HUDManager::remove(HUDElement* element)
{
	elements.erase(element);
}
	
HUDManager::HUDManager(int width, int heigth) 
	: width(width), heigth(heigth)
{
}

HUDManager::~HUDManager(void)
{
}
