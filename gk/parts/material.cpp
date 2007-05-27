#include "material.hpp"
#include "opengl.hpp"

material::material()
: ambient(1, 0, 0), shininess(0)
{
}

void material::compile()
{
	texture.compile();
}

void material::draw() const
{
	texture.draw();

	glMaterialfv(GL_FRONT, GL_AMBIENT, &ambient.vector()[0]);
	glMaterialfv(GL_FRONT, GL_DIFFUSE, &diffuse.vector()[0]);
	glMaterialfv(GL_FRONT, GL_SPECULAR, &specular.vector()[0]);
	glMaterialfv(GL_FRONT, GL_EMISSION, &emission.vector()[0]);

	glMaterialf(GL_FRONT, GL_SHININESS, shininess);
}

material_scope::material_scope(const material& material)
{
	glPushAttrib(GL_TEXTURE_BIT | GL_LIGHTING_BIT);
	_ASSERTE(glGetError() == GL_NO_ERROR);
	
	material.draw();
}

material_scope::~material_scope()
{
	glPopAttrib();
	_ASSERTE(glGetError() == GL_NO_ERROR);
}

