#include "Character.hpp"

#include <iostream>
#include <cmath>

using namespace boost::numeric::ublas;
	
Character::Character(const NewtonWorld* nw, float sizeX, float sizeY, float sizeZ, float locationX, float locationY, float locationZ)
	:nWorld(nw)
{
	normal[0] = normal[2] = 0;
	normal[1] = 1;
	
	size[0] = sizeX;
	size[1] = sizeY;
	size[2] = sizeZ;

	location = identity_matrix<float>(4);
	location(3,0) = locationX;
	location(3,1) = locationY;
	location(3,2) = locationZ;

	NewtonCollision* collision = NewtonCreateSphere(nWorld, size[0], size[1], size[2], NULL);
	body = NewtonCreateBody(nWorld, collision);
	NewtonReleaseCollision(nWorld, collision);
	
	NewtonBodySetUserData(body, this);

	NewtonBodySetDestructorCallback(body, destructor);
	NewtonBodySetTransformCallback(body, setTransform);
	NewtonBodySetForceAndTorqueCallback(body, applyForceAndTorque);

	NewtonBodySetMassMatrix(body, 80.0f, 80.0f, 80.0f, 80.0f);

	NewtonBodySetMatrix(body, location.data());
	
  	upVector = NewtonConstraintCreateUpVector(nWorld, createVector(0, 1, 0).data(), body); 

	NewtonBodySetAutoFreeze(body, 0);

	NewtonWorldUnfreezeBody(nWorld, body);

	jumpInd = false;
	jumping = false;
	count = 0;
}

Character::~Character(void)
{
}

void Character::applyForceAndTorque(const NewtonBody* body)
{
	Character* player;

	player = (Character*)NewtonBodyGetUserData(body);

	player->applyForceAndTorque();
}

void Character::setTransform(const NewtonBody* body, const float* matrix)
{
	Character* player;

	player = (Character*)NewtonBodyGetUserData(body);

	Matrix4x4 mat;
	for (int i = 0; i < 4; ++i)
		for (int j = 0; j < 4; ++j)
			mat(i,j) = matrix[i*4 + j];

	player->setLocation(mat);
}

void Character::destructor(const NewtonBody* body)
{
	Character* player = (Character*)NewtonBodyGetUserData(body);
	delete player;
}

void Character::setLocation(const Matrix4x4& matrix)
{
	location = matrix;
}

void Character::move(const Vector& v)
{
	movement = v;
}

void Character::jump()
{
	if (!jumping)
		jumpInd = true;
}

Vector Character::getLocation()
{
	return matrix_row<Matrix4x4>(location, 3);
}

Vector Character::getDirection()
{
	return matrix_row<Matrix4x4>(location, 0);
}

void Character::processCollision(const NewtonMaterial* material)
{
	NewtonMaterialSetContactFrictionState(material, 0, 0);
	NewtonMaterialSetContactFrictionState(material, 0, 1);

	if (count)
	{
		count--;
		normal[0] = normal[2] = 0.0f;
		normal[1] = 1.0f;
	}
	else
	{
		jumping = false;
	}
}

void Character::applyForceAndTorque()
{
	dFloat Ixx;
	dFloat Iyy;
	dFloat Izz;
	dFloat mass;

	float timestep = NewtonGetTimeStep(nWorld);
	
	NewtonBodyGetMassMatrix (body, &mass, &Ixx, &Iyy, &Izz);

	Vector desiredVel;
		
	if (norm_2(movement) > 0.0001f)
	{
		movement /= norm_2(movement);
		//desiredVel = cross_prod(normal, cross_prod(movement, normal));
		desiredVel = movement;
		desiredVel *= 6.0f;
	}
	else
	{
		desiredVel = movement * 0.0f;
	}

	NewtonBodyGetVelocity(body, velocity.data());
	
	if (velocity[1] < 0 || jumping)
		velocity[1] = 0;

	float k = (!jumping) ? 0.2f : 0.05f;

	Vector force = k * mass * (desiredVel - velocity) / timestep;
	force += createVector(0, -mass * 9.8f, 0);

	if (jumpInd)
	{
		force[1] += mass * (5.0f - velocity[1]) / timestep;
		jumpInd = false;
		jumping = true;
		count = 4;
	}

	NewtonBodySetForce(body, force.data());
}

void Character::draw(const state& state) const
{
	NewtonBodyGetVelocity(body, velocity.data());
	velocity[3] = 0;
	write(350, 35, "VELOCITY (%3.1f, %3.1f, %3.1f)", velocity[0], velocity[1], velocity[2]);
	if (jumping)
		write(350, 55, "JUMPING");
	write(350, 75, "SPEED (%3.1f)", norm_2(velocity));
}