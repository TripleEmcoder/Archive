#include "scope.hpp"
#include "matrix.hpp"
#include "id.hpp"
#include "engine.hpp"

matrix_scope::matrix_scope(const matrix& composition)
{
	glPushMatrix();
	_ASSERTE(glGetError() == GL_NO_ERROR);
	
	glMultMatrixf(composition.row_major_data());
	_ASSERTE(glGetError() == GL_NO_ERROR);
}

matrix_scope::~matrix_scope()
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
