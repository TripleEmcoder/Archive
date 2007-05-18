#include "material.hpp"
#include "engine.hpp"

material::material()
: color(1, 1, 1), shininess(0)
{
}

material::material(const vertex& color)
: color(color), shininess(0)
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

	glMaterialfv(GL_FRONT, GL_AMBIENT, &ambient.vector()[0]);
	glMaterialfv(GL_FRONT, GL_DIFFUSE, &diffuse.vector()[0]);
	glMaterialfv(GL_FRONT, GL_SPECULAR, &specular.vector()[0]);
	glMaterialfv(GL_FRONT, GL_EMISSION, &emission.vector()[0]);
	glMaterialf(GL_FRONT, GL_SHININESS, shininess);
}
