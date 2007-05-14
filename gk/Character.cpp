#include "Character.hpp"

#include <iostream>

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

	NewtonCollision* sphere = NewtonCreateSphere(nWorld, size[0], size[1], size[2], NULL);
	//NewtonCollision* collision = NewtonCreateConvexHullModifier(nWorld, sphere);
	
	body = NewtonCreateBody(nWorld, sphere);
	//NewtonReleaseCollision(nWorld, collision);
	NewtonReleaseCollision(nWorld, sphere);		
	
	NewtonBodySetUserData(body, this);

	// set a destructor for this rigid body
	//NewtonBodySetDestructorCallback(body, PhysicsBodyDestructor);

	// set the transform call back function
	NewtonBodySetTransformCallback(body, setTransform);

	// set the force and torque call back function
	NewtonBodySetForceAndTorqueCallback(body, applyForceAndTorque);

	// set the mass matrix
	NewtonBodySetMassMatrix(body, 10.0f, 10.0f, 10.0f, 10.0f);

	// set the matrix for both the rigid body and the graphic body
	NewtonBodySetMatrix(body, location.data());
	
  	// add and up vector constraint to help in keeping the body upright
	Vector upDirection;
	upDirection[0] = 0.0;
	upDirection[1] = 1.0;
	upDirection[2] = 0.0;
	upDirection[3] = 0.0;
	upVector = NewtonConstraintCreateUpVector(nWorld, upDirection.data(), body); 

	NewtonBodySetAutoFreeze(body, 0);

	NewtonWorldUnfreezeBody(nWorld, body);
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

void Character::setLocation(const Matrix& matrix)
{
	location = matrix;
}

void Character::setForce(const Vector& f)
{
	std::cerr << "Character::setForce(const Vector& f)" << std::endl;
	force = f;
	std::cerr << force[0] << " " << force[1] << " " << force[2] << " " << std::endl;
	std::cerr << "Character::setForce(const Vector& f) exit" << std::endl;
}

Vector Character::getLocation()
{
	return matrix_row<Matrix>(location, 3);
}

Vector Character::getDirection()
{
	return matrix_row<Matrix>(location, 0);
}


void Character::applyForceAndTorque()
{
	dFloat Ixx;
	dFloat Iyy;
	dFloat Izz;
	dFloat mass;

	
	NewtonBodyGetMassMatrix (body, &mass, &Ixx, &Iyy, &Izz);
	float torque[] = {0.0f, 10.0f, 0.0f};
	std::cerr << "Character::applyForceAndTorque()" << std::endl;
	std::cerr << force[0] << " " << force[1] << " " << force[2] << " " << std::endl;
	NewtonBodySetVelocity(body, force.data());
	std::cerr << "Character::applyForceAndTorque() exit" << std::endl;
	//NewtonBodySetTorque(body, torque);
}