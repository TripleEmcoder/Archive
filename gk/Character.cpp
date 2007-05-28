#include "Character.hpp"
#include "matrix.hpp"
#include "vertex.hpp"

#include <iostream>
#include <cmath>

#include <boost/bind.hpp>

//using boost::numeric::ublas;
	
Character::Character(const world_wrapper& nw, float sizeX, float sizeY, float sizeZ, float locationX, float locationY, float locationZ)
	:nWorld(nw.id()), body(nw, "character")
{
	body.mass(80.0f, vertex(80.0f, 80.0f, 80.0f));

	body.transformation_changed.connect(boost::bind(&Character::setTransform, this, _1));
	body.simulation_starting.connect(boost::bind(&Character::applyForceAndTorque, this));
	body.contact_running.connect(boost::bind(&Character::processCollision, this));

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
	NewtonBodySetCollision(body.id(), collision);
	NewtonReleaseCollision(nWorld, collision);

	NewtonBodySetMatrix(body.id(), location.data());
	
  	upVector = NewtonConstraintCreateUpVector(nWorld, createVector(0, 1, 0).data(), body.id()); 

	NewtonBodySetAutoFreeze(body.id(), 0);

	NewtonWorldUnfreezeBody(nWorld, body.id());

	jumpInd = false;
	jumping = false;
	count = 0;
}

Character::~Character(void)
{
}

void Character::setTransform(const matrix& value)
{
	const float* m = value.row_major_data();

	Matrix4x4 mat;
	for (int i = 0; i < 4; ++i)
		for (int j = 0; j < 4; ++j)
			mat(i,j) = m[i*4 + j];

	setLocation(mat);
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

void Character::processCollision()
{
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
	
	NewtonBodyGetMassMatrix(body.id(), &mass, &Ixx, &Iyy, &Izz);

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

	NewtonBodyGetVelocity(body.id(), velocity.data());
	
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

	NewtonBodySetForce(body.id(), force.data());
}

void Character::draw(const state& state) const
{
	NewtonBodyGetVelocity(body.id(), velocity.data());
	velocity[3] = 0;
	write(350, 35, "VELOCITY (%3.1f, %3.1f, %3.1f)", velocity[0], velocity[1], velocity[2]);
	if (jumping)
		write(350, 55, "JUMPING");
	write(350, 75, "SPEED (%3.1f)", norm_2(velocity));
}