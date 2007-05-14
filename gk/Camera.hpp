#pragma once

#include "HUDElement.hpp"
#include "math.hpp"

class Camera : public HUDElement
{
private:
	Vector eye, direction;
	float angleX, angleY;
public:
	Camera(float eyeX, float eyeY, float eyeZ, float angleX, float angleY);
	~Camera(void);
	void draw();
	virtual void drawHUD();
	void setEye(const Vector& eye);
	void setDirection(const Vector& eye);
	void rotate(float x, float y);
	Matrix getRotationMatrix();
};
