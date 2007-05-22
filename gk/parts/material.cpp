#include "material.hpp"
#include "engine.hpp"

material::material()
: ambient(1, 0, 0), shininess(0)
{
}

void material::compile()
{
	texture.compile();
}

void material::draw(const state& state) const
{
	texture.draw(state);

	glMaterialfv(GL_FRONT, GL_AMBIENT, &ambient.vector()[0]);
	glMaterialfv(GL_FRONT, GL_DIFFUSE, &diffuse.vector()[0]);
	glMaterialfv(GL_FRONT, GL_SPECULAR, &specular.vector()[0]);
	glMaterialfv(GL_FRONT, GL_EMISSION, &emission.vector()[0]);

	glMaterialf(GL_FRONT, GL_SHININESS, shininess);
}
