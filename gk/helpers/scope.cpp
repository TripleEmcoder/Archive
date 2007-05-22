#include "scope.hpp"
#include "matrix.hpp"
#include "material.hpp"
#include "id.hpp"
#include "engine.hpp"

matrix_scope::matrix_scope(const matrix& matrix)
{
	glPushMatrix();
	_ASSERTE(glGetError() == GL_NO_ERROR);
	
	glMultMatrixf(matrix.row_major_data());
	_ASSERTE(glGetError() == GL_NO_ERROR);
}

matrix_scope::~matrix_scope()
{
	glPopMatrix();
	_ASSERTE(glGetError() == GL_NO_ERROR);
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
