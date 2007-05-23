#include "id.hpp"
#include "engine.hpp"

texture_id::texture_id()
{
	glGenTextures(1, &texture);
	_ASSERTE(glGetError() == GL_NO_ERROR);
}

texture_id::~texture_id()
{
	glDeleteTextures(1, &texture);
	_ASSERTE(glGetError() == GL_NO_ERROR);
}

texture_id::operator unsigned int() const
{
	return texture;
}

list_id::list_id()
{
	list = glGenLists(1);
	_ASSERTE(glGetError() == GL_NO_ERROR);
}

list_id::~list_id()
{
	glDeleteLists(list, 1);
	_ASSERTE(glGetError() == GL_NO_ERROR);
}

list_id::operator unsigned int() const
{
	return list;
}

world_id::world_id()
{
	world = NewtonCreate(NULL, NULL);
}

world_id::~world_id()
{
	NewtonDestroy(world);
}

world_id::operator NewtonWorld*() const
{
	return world;
}

body_id::body_id(world_id& world)
:
	world(world)
{
	NewtonCollision* collision = NewtonCreateNull(world);
	body = NewtonCreateBody(world, collision);
	NewtonReleaseCollision(world, collision);
}

body_id::~body_id()
{
	NewtonDestroyBody(world, body);
}

body_id::operator NewtonBody*() const
{
	return body;
}
