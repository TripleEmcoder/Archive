#include "newton.hpp"
#include "matrix.hpp"
#include "vertex.hpp"

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

body_id::body_id(const world_id& world)
{
	NewtonCollision* collision = NewtonCreateNull(world);
	body = NewtonCreateBody(world, collision);
	NewtonReleaseCollision(world, collision);
}

body_id::~body_id()
{
	NewtonDestroyBody(NewtonBodyGetWorld(body), body);
}

body_id::operator NewtonBody*() const
{
	return body;
}

void transformation_callback(const NewtonBody* body, const float*)
{
	body_wrapper* wrapper = (body_wrapper*) NewtonBodyGetUserData(body);
	matrix matrix;
	NewtonBodyGetMatrix(body, matrix.row_major_data());
	wrapper->transformation_changed(matrix);
}

body_wrapper::body_wrapper(const world_id& world)
:
	body(world)
{
	NewtonBodySetUserData(body, this);
	NewtonBodySetTransformCallback(body, transformation_callback);

	NewtonCollision* collision = NewtonCreateBox(world,	0.1, 0.1, 0.1, NULL);
	NewtonBodySetCollision(body, collision);
	NewtonReleaseCollision(world, collision);
}

void body_wrapper::transformation(const matrix& value)
{
	NewtonBodySetMatrix(body, value.row_major_data());
}

void body_wrapper::mass(float mass, const vertex& inertia)
{
	NewtonBodySetMassMatrix(body, mass, inertia.x, inertia.y, inertia.z);	
}

void body_wrapper::omega(const vertex& value)
{
	NewtonBodySetOmega(body, &value.x);
}
