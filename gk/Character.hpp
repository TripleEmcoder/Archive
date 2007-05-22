#pragma once

#include <Newton.h>
#include "math.hpp"
#include "widgets/display.hpp"

class Character : public widget
{
private:
	static void applyForceAndTorque(const NewtonBody* body);
	static void setTransform(const NewtonBody* body, const float* matrix);
	static void destructor(const NewtonBody* body);
	static const int BODY_COLLISION = 1;
	static const int FEET_COLLISION = 2;
	
	Matrix location;
	mutable Vector size, velocity, movement, normal;
	int count;
	bool jumpInd, jumping;
	NewtonBody* body;
	const NewtonWorld* nWorld;
	NewtonJoint* upVector;
	void applyForceAndTorque();
	void setLocation(const Matrix& matrix);
public:
	Character(const NewtonWorld* nw, float sizeX, float sizeY, float sizeZ, float locationX, float locationY, float locationZ);
	Vector getLocation();
	Vector getDirection();
	virtual void draw(const state& state) const;
	void move(const Vector& v);
	void jump();
	void processCollision(const NewtonMaterial* material);
	~Character(void);
};
