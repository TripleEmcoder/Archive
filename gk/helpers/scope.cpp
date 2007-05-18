#include "scope.hpp"
#include "transformation.hpp"
#include "engine.hpp"

scope::scope(const transformation& composition)
{
	glPushMatrix();
	_ASSERT(glGetError() == GL_NO_ERROR);
	
	glMultMatrixf(composition.row_major_data());
	_ASSERT(glGetError() == GL_NO_ERROR);
}

scope::~scope()
{
	glPopMatrix();
	_ASSERT(glGetError() == GL_NO_ERROR);
}
