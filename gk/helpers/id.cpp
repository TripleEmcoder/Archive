#include "id.hpp"
#include "engine.hpp"

#include <cassert>

texture_id::texture_id()
{
	glGenTextures(1, &id);
	_ASSERTE(glGetError() == GL_NO_ERROR);
}

texture_id::~texture_id()
{
	glDeleteTextures(1, &id);
	_ASSERTE(glGetError() == GL_NO_ERROR);
}

texture_id::operator unsigned int() const
{
	return id;
}

list_id::list_id()
{
	id = glGenLists(1);
	_ASSERTE(glGetError() == GL_NO_ERROR);
}

list_id::~list_id()
{
	glDeleteLists(id, 1);
	_ASSERTE(glGetError() == GL_NO_ERROR);
}

list_id::operator unsigned int() const
{
	return id;
}
