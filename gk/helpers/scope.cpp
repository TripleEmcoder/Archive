#include "scope.hpp"
#include "transformation.hpp"
#include "id.hpp"
#include "engine.hpp"

transformation_scope::transformation_scope(const transformation& composition)
{
	glPushMatrix();
	_ASSERTE(glGetError() == GL_NO_ERROR);
	
	glMultMatrixf(composition.row_major_data());
	_ASSERTE(glGetError() == GL_NO_ERROR);
}

transformation_scope::~transformation_scope()
{
	glPopMatrix();
	_ASSERTE(glGetError() == GL_NO_ERROR);
}

list_scope::list_scope(const list_id& id)
{
	glNewList(id, GL_COMPILE);
	_ASSERTE(glGetError() == GL_NO_ERROR);
}

list_scope::~list_scope()
{
	glEndList();
	_ASSERTE(glGetError() == GL_NO_ERROR);
}
