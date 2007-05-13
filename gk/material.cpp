#include "material.hpp"
#include "cache.hpp"

material::material(std::string texture)
: texture(texture)
{
}

#include <windows.h>
#include <GL/gl.h>

void material::draw() const
{
	glBindTexture(GL_TEXTURE_2D, cache::texture(texture));
}