#pragma once

#include <Newton.h>
#include "math.hpp"
#include "widget.hpp"
#include "newton.hpp"
#include "vertex.hpp"

class Character : public widget
{
private:
	static const int BODY_COLLISION = 1;
	static const int FEET_COLLISION = 2;
	
	Matrix4x4 location;
	mutable Vector movement;
	vertex size;
	int count;
	bool jumpInd, jumping;
	body_wrapper body;
	const NewtonWorld* nWorld;
	NewtonJoint* upVector;
	void applyForceAndTorque();
	void setTransform(const matrix& matrix);
public:
	Character(const world_wrapper& nw, vertex size, vertex position);
	Vector getLocation();
	Vector getDirection();
	virtual void draw(const state& state) const;
	void move(const Vector& v);
	void jump();
	void processCollision();
	~Character(void);
};
