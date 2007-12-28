#pragma once

#include "widget.hpp"
#include "math.hpp"

struct plane
{
	Vector normal;
	float distance;
};

#include "vertex.hpp"

class Camera : public widget
{
private:
	enum {TOP_PLANE = 0, BOTTOM_PLANE, LEFT_PLANE, RIGHT_PLANE, NEAR_PLANE, FAR_PLANE};
	mutable Matrix4x4 matrix;
	float angleX, angleY;
	float nearDistance, farDistance, ratio, angle;
	mutable float nearWidth, nearHeigth, farWidth, farHeigth;
	mutable plane planes[6];
	void calculatePlanes() const;
public:
	Camera(float angleX, float angleY);
	~Camera(void);
	//void draw();
	virtual void draw(const state& state) const;
	virtual void set() const;
	void rotate(float x, float y);
	float getAngleX() const;
	float getAngleY() const;
	void setPosition(const Vector& position);
	Vector getPosition() const;
	void setCameraInternals(float angle, float ratio, float nearD, float farD);
	bool isVisible(const int mins[3], const int maxs[3]) const;
};
