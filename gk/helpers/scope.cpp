#include "scope.hpp"
//#include "transformation.hpp"
#include "object.hpp"
#include "engine.hpp"

//scope::scope(const transformation& composition)
scope::scope(const object& owner)
{
	glPushMatrix();
	//glMultMatrixf(composition.row_major_data());
	glMultMatrixf(owner.composition->row_major_data());
	//glRotated(owner.rotation.x, 1, 0, 0);
	//glRotated(owner.rotation.y, 0, 1, 0);
	//glRotated(owner.rotation.z, 0, 0, 1);
}

scope::~scope()
{
	glPopMatrix();
}
