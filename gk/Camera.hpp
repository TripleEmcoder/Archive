#pragma once

#include "display.hpp"
#include "math.hpp"

class Camera : public display
{
private:
	mutable Vector eye, direction;
	mutable Matrix rotation;
	float angleX, angleY;
public:
	Camera(float eyeX, float eyeY, float eyeZ, float angleX, float angleY);
	~Camera(void);
	//void draw();
	virtual void draw(const state& state) const;
	void setEye(const Vector& eye);
	void rotate(float x, float y);
	float getAngleX();
	float getAngleY();
	Matrix getRotationMatrix();
};
