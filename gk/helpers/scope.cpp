#include "scope.hpp"
#include "transformation.hpp"
#include "engine.hpp"

scope::scope(const transformation& composition)
{
	glPushMatrix();
	glMultMatrixf(composition.row_major_data());
}

scope::~scope()
{
	glPopMatrix();
}
