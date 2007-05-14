#pragma once

#include <Newton.h>
#include "math.hpp"

class Character
{
private:
	static void applyForceAndTorque(const NewtonBody* body);
	static void setTransform(const NewtonBody* body, const float* matrix);
	Matrix location;
	Vector size, force;
	NewtonBody* body;
	NewtonWorld* nWorld;
	NewtonJoint* upVector;
	void applyForceAndTorque();
	void setLocation(const Matrix& matrix);
public:
	Character(NewtonWorld* nw, float sizeX, float sizeY, float sizeZ, float locationX, float locationY, float locationZ);
	Vector getLocation();
	Vector getDirection();
	void setForce(const Vector& force);
	~Character(void);
};
