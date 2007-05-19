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

	matrix_row<Matrix> row(location, 3);
	row[0] = locationX;
	row[1] = locationY;
	row[2] = locationZ;

	NewtonCollision* collisionParts[2];

	collisionParts[0] = NewtonCreateSphere(nWorld, size[0], size[1], size[2], NULL);
	collisionParts[1] = NewtonCreateBox(nWorld, size[0]/2, 0.05f, size[2]/2, translationMatrix(0, -size[1]-0.1f, 0).data());
	NewtonConvexCollisionSetUserID(collisionParts[0], BODY_COLLISION);
	NewtonConvexCollisionSetUserID(collisionParts[1], FEET_COLLISION);
	NewtonCollision* collision = NewtonCreateCompoundCollision(nWorld, 2, collisionParts);
	
	body = NewtonCreateBody(nWorld, collision);
	NewtonReleaseCollision(nWorld, collisionParts[0]);
	NewtonReleaseCollision(nWorld, collisionParts[1]);		
	
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
	jumping = true;
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

	Matrix mat;
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

void Character::setLocation(const Matrix& matrix)
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
	return matrix_row<Matrix>(location, 3);
}

Vector Character::getDirection()
{
	return matrix_row<Matrix>(location, 0);
}

void Character::processCollision(const NewtonMaterial* material)
{
	Vector position;
	NewtonMaterialGetContactPositionAndNormal(material, position.data(), normal.data());

	int collisionID = NewtonMaterialGetBodyCollisionID(material, body);
	if (collisionID == FEET_COLLISION)
	{
		NewtonMaterialSetContactElasticity(material, 0.2f);
		NewtonMaterialSetContactFrictionState(material, 1, 0);
		NewtonMaterialSetContactFrictionState(material, 1, 1);
		if (count)
		{
			count--;
			normal[0] = normal[2] = 0.0f;
			normal[1] = 1.0f;
		}
		else
			jumping = false;
	}
	else if (collisionID == BODY_COLLISION)
	{
		NewtonMaterialSetContactFrictionState(material, 0, 0);
		NewtonMaterialSetContactFrictionState(material, 0, 1);
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
		desiredVel = cross_prod(normal, cross_prod(movement, normal));
		//desiredVel = movement;
		desiredVel *= 6.0;
	}
	else
	{
		desiredVel = movement * 0.0f;
	}

	NewtonBodyGetVelocity(body, velocity.data());
	
	if (velocity[1] < 0 || jumping)
		velocity[1] = 0;

	float k = (!jumping) ? 0.2f : 0.05f;
	//k *= 10;

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

void Character::drawHUD()
{
	NewtonBodyGetVelocity(body, velocity.data());
	velocity[3] = 0;
	renderBitmapString(350, 35, 1.0f, 0.0f, 0.0f, "VELOCITY (%3.1f, %3.1f, %3.1f)", velocity[0], velocity[1], velocity[2]);
	if (jumping)
		renderBitmapString(350, 55, 1.0f, 0.0f, 0.0f, "JUMPING");
	renderBitmapString(350, 75, 1.0f, 0.0f, 0.0f, "NORMAL (%3.1f, %3.1f, %3.1f)", normal[0], normal[1], normal[2]);
	renderBitmapString(350, 95, 1.0f, 0.0f, 0.0f, "SPEED (%3.1f)", norm_2(velocity));
}