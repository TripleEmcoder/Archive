#include "projector.hpp"
#include "widget.hpp"
#include "opengl.hpp"

#include <algorithm>

#include <boost/bind.hpp>

using boost::ref;
using boost::bind;

projector::projector(const vertex& color)
:
	color(color)
{
}

void projector::add(const widget* item)
{
	_widgets.insert(item);
}
void projector::remove(const widget* item)
{
	_widgets.erase(item);
}

void projector::draw(const state& state) const
{
	int width = glutGet(GLUT_WINDOW_WIDTH);
	int height = glutGet(GLUT_WINDOW_HEIGHT);
	
	glMatrixMode(GL_MODELVIEW);
	glPushMatrix();
	glLoadIdentity();

	glMatrixMode(GL_PROJECTION);
	glPushMatrix();
	glLoadIdentity();
	gluOrtho2D(0, width, 0, height);

	glPushAttrib(GL_ENABLE_BIT | GL_CURRENT_BIT);

	glDisable(GL_DEPTH_TEST);
	glDisable(GL_TEXTURE_2D);
	glDisable(GL_LIGHTING);

	glColor3f(color.x, color.y, color.z);

	std::for_each(_widgets.begin(), _widgets.end(), bind(&widget::draw, _1, ref(state)));
	
	glMatrixMode(GL_PROJECTION);
	glPopMatrix();

	glMatrixMode(GL_MODELVIEW);
	glPopMatrix();

	glPopAttrib();
}
