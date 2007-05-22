#include "Camera.hpp"

#include <windows.h>
#include <GL/gl.h>
#include <GL/glu.h>
#include <GL/glut.h>

Camera::Camera(float eyeX, float eyeY, float eyeZ, float x, float y)
{
	angleX = angleY = 0;
	eye[0] = eyeX;
	eye[1] = eyeY;
	eye[2] = eyeZ;
	rotate(x, y);
}

Camera::~Camera(void)
{
}

void Camera::rotate(float x, float y)
{
	angleX += x;
	angleY += y;
	if (angleY >= 89.0f * 3.1416f / 180.0f)
		angleY = 89.0f * 3.1416f / 180.0f;
	if (angleY <= -89.0f * 3.1416f / 180.0f)
		angleY = -89.0f * 3.1416f / 180.0f;
	rotation = prod(rollMatrix(angleY), yawMatrix(angleX));
}

void Camera::setEye(const Vector& e)
{
	eye = e;
}

void Camera::set(const state& state) const
{
	direction = matrix_row<Matrix>(rotation, 0);
	Vector center = eye + direction;		
	gluLookAt(eye[0], eye[1], eye[2], center[0], center[1], center[2], 0, 1, 0);
}

void Camera::draw(const state& state) const
{
	write(650, 35, "(%3.1f, %3.1f, %3.1f)", eye[0], eye[1], eye[2]);
	write(650, 55, "(%3.1f, %3.1f, %3.1f)", direction[0], direction[1], direction[2]);
	write(650, 75, "(%3.1f, %3.1f)", angleX, angleY);
}

Matrix Camera::getRotationMatrix()
{
	return rotation;
}

float Camera::getAngleX() const
{
	return angleX;
}

float Camera::getAngleY() const
{
	return angleY;
}
