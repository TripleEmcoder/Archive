#include "material.hpp"
#include "engine.hpp"

material::material()
: color(1, 1, 1)
{
}

material::material(const vertex& color)
: color(color)
{
}

void material::compile()
{
	texture.compile();
}

void material::draw() const
{
	texture.draw();

	glColor3f(color.x, color.y, color.z);
	//glMaterialfv(GL_FRONT, GL_AMBIENT, ambient);
	//glMaterialfv(GL_FRONT, GL_DIFFUSE, diffuse);
	//glMaterialfv(GL_FRONT, GL_SPECULAR, specular);
	//glMaterialf(GL_FRONT, GL_SHININESS, shininess);
}
