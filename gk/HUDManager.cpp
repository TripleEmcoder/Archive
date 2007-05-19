#include "HUDManager.hpp"

#include <GL/glut.h>
#include <algorithm>
#include <functional>

void HUDManager::setOrthographicProjection() 
{
	int width = glutGet(GLUT_WINDOW_WIDTH);
	int height = glutGet(GLUT_WINDOW_HEIGHT);
	
	glDisable(GL_LIGHTING);
	glDisable(GL_TEXTURE_2D);

	glMatrixMode(GL_TEXTURE);
	glPushMatrix();
	glLoadIdentity();

	glMatrixMode(GL_PROJECTION);
	glPushMatrix();
	glLoadIdentity();
	gluOrtho2D(0, width, 0, height);
	glScalef(1, -1, 1);
	glTranslatef(0, -height, 0);

	glMatrixMode(GL_MODELVIEW);
	glPushMatrix();
	glLoadIdentity();

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
	//glEnable(GL_LIGHTING);
	//glEnable(GL_TEXTURE_2D);
}

void HUDManager::draw()
{
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
	
HUDManager::HUDManager() 
{
}

HUDManager::~HUDManager(void)
{
}
