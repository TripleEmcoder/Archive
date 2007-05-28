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

int world_wrapper::contact_started_callback(const NewtonMaterial* material, const NewtonBody* body0, const NewtonBody* body1)
{
	world_wrapper* wrapper = (world_wrapper*) NewtonMaterialGetMaterialPairUserData(material);

	_ASSERTE(wrapper->body0 == NULL);
	_ASSERTE(wrapper->body1 == NULL);

	wrapper->body0 = (body_wrapper*) NewtonBodyGetUserData(body0);
	wrapper->body1 = (body_wrapper*) NewtonBodyGetUserData(body1);

	wrapper->body0->contact_started(*wrapper->body1);
	wrapper->body1->contact_started(*wrapper->body0);

	return 1;
}

int world_wrapper::contact_running_callback(const NewtonMaterial* material, const NewtonContact* contact)
{
	NewtonMaterialSetContactFrictionState(material, 0, 0);
	NewtonMaterialSetContactFrictionState(material, 0, 1);

	world_wrapper* wrapper = (world_wrapper*) NewtonMaterialGetMaterialPairUserData(material);

	_ASSERTE(wrapper->body0 != NULL);
	_ASSERTE(wrapper->body1 != NULL);

	wrapper->body0->contact_running(*wrapper->body1);
	wrapper->body1->contact_running(*wrapper->body0);

	return 1;
}

void world_wrapper::contact_stopped_callback(const NewtonMaterial* material)
{
	world_wrapper* wrapper = (world_wrapper*) NewtonMaterialGetMaterialPairUserData(material);

	_ASSERTE(wrapper->body0 != NULL);
	_ASSERTE(wrapper->body1 != NULL);

	wrapper->body0->contact_stopped(*wrapper->body1);
	wrapper->body1->contact_stopped(*wrapper->body0);

	wrapper->body0 = NULL;
	wrapper->body1 = NULL;
}

world_wrapper::world_wrapper()
:
	body0(NULL), body1(NULL)
{
	int material = NewtonMaterialGetDefaultGroupID (world);

	NewtonMaterialSetDefaultSoftness(world, material, material, 0.05f);
	NewtonMaterialSetDefaultElasticity(world, material, material, 0.0f);
	NewtonMaterialSetDefaultCollidable(world, material, material, 1);
	//NewtonMaterialSetDefaultFriction(world, material, material, 0.0f, 0.0f);
	
	NewtonMaterialSetCollisionCallback(world, material, material, this,
		contact_started_callback, contact_running_callback, contact_stopped_callback);
}

const world_id& world_wrapper::id() const
{
	return world;
}

void world_wrapper::size(const vertex& lower_bound, const vertex& upper_bound)
{
	NewtonSetWorldSize(world, &lower_bound.x, &upper_bound.x);
}

void body_wrapper::transformation_changed_callback(const NewtonBody* body, const float* matrix)
{
	body_wrapper* wrapper = (body_wrapper*) NewtonBodyGetUserData(body);
	::matrix value;
	NewtonBodyGetMatrix(body, value.row_major_data());
	wrapper->transformation_changed(value);
}

void body_wrapper::simulation_starting_callback(const NewtonBody* body)
{
	body_wrapper* wrapper = (body_wrapper*) NewtonBodyGetUserData(body);
	wrapper->simulation_starting();
}

body_wrapper::body_wrapper(const world_wrapper& world)
:
	body(world.id())
{
	NewtonBodySetUserData(body, this);
	NewtonBodySetTransformCallback(body, transformation_changed_callback);
	NewtonBodySetForceAndTorqueCallback(body, simulation_starting_callback);
}

const body_id& body_wrapper::id() const
{
	return body;
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
