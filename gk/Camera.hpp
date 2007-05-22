#pragma once

#include "widget.hpp"
#include "math.hpp"

class Camera : public widget
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
	virtual void set(const state& state) const;
	void setEye(const Vector& eye);
	void rotate(float x, float y);
	float getAngleX() const;
	float getAngleY() const;
	Matrix getRotationMatrix();
};
