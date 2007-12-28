#include "about.hpp"
#include "opengl.hpp"

void about::draw(const state& state) const
{
	float x = glutGet(GLUT_WINDOW_WIDTH) - 230;
	write(x, 70, "BARTOSZ KUKAWKA");
	write(x, 50, "MARCIN MIKOLAJCZAK");
	write(x, 30, "GRAFIKA KOMPUTEROWA 2007");
}