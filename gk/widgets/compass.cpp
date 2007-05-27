#include "compass.hpp"
#include "state.hpp"
#include "../Camera.hpp"
#include "matrix.hpp"
#include "opengl.hpp"

#include <cmath>

compass::compass(float radius)
:
	radius(radius)
{
}

void compass::draw(const state& state) const
{
	glPushMatrix();
	glTranslatef(120, 150, 0);
	glRotatef(radians_to_degrees(state.camera->getAngleX()), 0, 0, 1);

	glBegin(GL_LINE_LOOP);
	
	for (int degrees=0; degrees<360; degrees++)
	{
		float radians = degrees_to_radians(degrees);
		glVertex2f(cos(radians)*radius, sin(radians)*radius);
	}

	glEnd();

	const float overflow = 0.4;

	glBegin(GL_LINE_LOOP);
	glVertex2f(0, (1+overflow-0.1)*radius);
	glVertex2f(-overflow*radius, -(1+overflow)*radius);
	glVertex2f(0, -(1-overflow)*radius);
	glVertex2f(overflow*radius, -(1+overflow)*radius);
	glEnd();

	const float margin = 0.6;

	write(0,  (1+margin)*radius, "N");
	write(0, -(1+margin)*radius, "S");
	write( (1+margin)*radius, 0, "W");
	write(-(1+margin)*radius, 0, "E");

	glPopMatrix();
}

void compass::write(float x, float y, std::string text) const
{
	float width = glutStrokeLength(GLUT_STROKE_ROMAN, 
		(const unsigned char*)text.c_str())*0.2/2;

	float height = 10;
	
	widget::write(x-width, y-height, GLUT_STROKE_ROMAN, 0.2, text);
}
