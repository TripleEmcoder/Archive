#include "Character.hpp"

#include <iostream>
#include <cmath>

using namespace boost::numeric::ublas;
	
Character::Character(NewtonWorld* nw, float sizeX, float sizeY, float sizeZ, float locationX, float locationY, float locationZ)
	:nWorld(nw)
{
	force[0] = force[1] = force[2] = 0.0f;
	
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
	int collisionID = NewtonMaterialGetBodyCollisionID(material, body);
	if (collisionID == FEET_COLLISION)
	{
		NewtonMaterialSetContactFrictionState(material, 1, 0);
		NewtonMaterialSetContactFrictionState(material, 1, 1);
		if (count)
			count--;
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
	
	NewtonBodyGetMassMatrix (body, &mass, &Ixx, &Iyy, &Izz);

	if (norm_2(movement) > 0.0001f)
		movement /= norm_2(movement);

	Vector force = createVector(0, -9.8f * mass, 0);
		
	if (!jumping)
	{
		NewtonBodyGetVelocity(body, velocity.data());
		
		movement *= 5.0f;
		velocity[0] = movement[0];
		velocity[2] = movement[2];

		NewtonBodySetVelocity(body, velocity.data());
	}
	else
	{
		force += movement * 1.0f * mass;
	}

	NewtonBodySetForce(body, force.data());
	
	if (jumpInd)
	{
		float jumpVelocity[] = {0.0f, 6.5f, 0.0f};
		NewtonAddBodyImpulse(body, jumpVelocity, getLocation().data());
		jumpInd = false;
		jumping = true;
		count = 4;
	}
}



void Character::drawHUD()
{
	NewtonBodyGetVelocity(body, velocity.data());
	renderBitmapString(350, 35, 1.0f, 0.0f, 0.0f, "(%3.1f, %3.1f, %3.1f)", velocity[0], velocity[1], velocity[2]);
	if (jumping)
		renderBitmapString(350, 55, 1.0f, 0.0f, 0.0f, "JUMPING");
}