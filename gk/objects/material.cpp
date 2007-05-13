#include "material.hpp"

#include "../helpers/cache.hpp"

material::material()
: texture(""), color(1, 1, 1)
{
}

material::material(std::string texture)
: texture(texture), color(1, 1, 1)
{
}

#include <windows.h>
#include <GL/gl.h>

void material::draw() const
{
	glBindTexture(GL_TEXTURE_2D, cache::texture(texture));
	glColor3d(color.x, color.y, color.z);
}