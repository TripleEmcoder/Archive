#include "HUDManager.hpp"

#include <GL/glut.h>
#include <algorithm>
#include <functional>

void HUDManager::setOrthographicProjection() 
{
	glDisable(GL_LIGHTING);
	glDisable(GL_TEXTURE_2D);

	glMatrixMode(GL_TEXTURE);
	glPushMatrix();
	glLoadIdentity();

	glMatrixMode(GL_PROJECTION);
	glPushMatrix();
	glLoadIdentity();
	gluOrtho2D(0, width, 0, heigth);
	glScalef(1, -1, 1);
	glTranslatef(0, -heigth, 0);

	glMatrixMode(GL_MODELVIEW);
	glPushMatrix();
	glLoadIdentity();

	glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
	glDisable(GL_DEPTH_TEST);
	glDisable(GL_BLEND);
}

void HUDManager::resetPerspectiveProjection() 
{
	glMatrixMode(GL_TEXTURE);
	glPopMatrix();

	glMatrixMode(GL_PROJECTION);
	glPopMatrix();

	glMatrixMode(GL_MODELVIEW);
	glPopMatrix();

	glEnable(GL_DEPTH_TEST);
	glEnable(GL_LIGHTING);
	glEnable(GL_TEXTURE_2D);
}

void HUDManager::draw()
{
	glColor3f(0.0f, 1.0f, 1.0f);
	glPushMatrix();
	glLoadIdentity();
	setOrthographicProjection();

	for_each(elements.begin(), elements.end(), std::mem_fun(&HUDElement::drawHUD));
	
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
