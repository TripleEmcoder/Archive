#include "projector.hpp"
#include "display.hpp"
#include "engine.hpp"

#include <algorithm>

#include <boost/bind.hpp>

using boost::ref;
using boost::bind;

void projector::add(const display* item)
{
	_displays.insert(item);
}
void projector::remove(const display* item)
{
	_displays.erase(item);
}

void projector::draw(const state& state) const
{
	setup_orthographic_projection();

	std::for_each(_displays.begin(), _displays.end(), bind(&display::draw, _1, ref(state)));
	
	setup_perspective_projection();
}


void projector::setup_orthographic_projection() const 
{
	int width = glutGet(GLUT_WINDOW_WIDTH);
	int height = glutGet(GLUT_WINDOW_HEIGHT);
	
	glMatrixMode(GL_TEXTURE);
	glPushMatrix();
	glLoadIdentity();

	glMatrixMode(GL_MODELVIEW);
	glPushMatrix();
	glLoadIdentity();

	glMatrixMode(GL_PROJECTION);
	glPushMatrix();
	glLoadIdentity();

	gluOrtho2D(0, width, 0, height);
	glScalef(1, -1, 1);
	glTranslatef(0, -height, 0);

	glPushAttrib(GL_ENABLE_BIT | GL_CURRENT_BIT);

	glDisable(GL_LIGHTING);
	glDisable(GL_TEXTURE_2D);
	glDisable(GL_DEPTH_TEST);
	glDisable(GL_BLEND);
}

void projector::setup_perspective_projection() const 
{
	glMatrixMode(GL_TEXTURE);
	glPopMatrix();

	glMatrixMode(GL_PROJECTION);
	glPopMatrix();

	glMatrixMode(GL_MODELVIEW);
	glPopMatrix();

	glPopAttrib();
}
