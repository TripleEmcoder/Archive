#pragma once

#include <Newton.h>
#include "math.hpp"
#include "HUDElement.hpp"

class Character : public HUDElement
{
private:
	static void applyForceAndTorque(const NewtonBody* body);
	static void setTransform(const NewtonBody* body, const float* matrix);
	static const int BODY_COLLISION = 1;
	static const int FEET_COLLISION = 2;
	Matrix location;
	Vector size, force, velocity, movement;
	bool jumpInd, jumping, skipCollision;
	NewtonBody* body;
	NewtonWorld* nWorld;
	NewtonJoint* upVector;
	void applyForceAndTorque();
	void setLocation(const Matrix& matrix);
public:
	Character(NewtonWorld* nw, float sizeX, float sizeY, float sizeZ, float locationX, float locationY, float locationZ);
	Vector getLocation();
	Vector getDirection();
	void drawHUD();
	void move(const Vector& v);
	void jump();
	void processCollision(const NewtonMaterial* material);
	~Character(void);
};
