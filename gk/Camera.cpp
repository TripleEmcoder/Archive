#include "Camera.hpp"

#include <windows.h>
#include <GL/gl.h>
#include <GL/glu.h>
#include <GL/glut.h>

Camera::Camera(float eyeX, float eyeY, float eyeZ, float angleX, float angleY)
{
	eye[0] = eyeX;
	eye[1] = eyeY;
	eye[2] = eyeZ;
	this->angleX = angleX;
	this->angleY = angleY; 
}

Camera::~Camera(void)
{
}

void Camera::rotate(float x, float y)
{
	angleX += x;
	angleY += y;
}

void Camera::setEye(const Vector& e)
{
	eye = e;
}

void Camera::setDirection(const Vector& d)
{
	direction = d;
}

void Camera::draw()
{
	direction = matrix_row<Matrix>(getRotationMatrix(), 0);
	//Vector direction = calculateDirection(angleX, angleY);
	Vector center = eye + direction;		
	gluLookAt(eye[0], eye[1], eye[2], center[0], center[1], center[2], 0, 1, 0);
}

void Camera::drawHUD()
{
	renderBitmapString(650, 35, 0.0f, 1.0f, 1.0f, "(%3.1f, %3.1f, %3.1f)", eye[0], eye[1], eye[2]);
	renderBitmapString(650, 55, 0.0f, 1.0f, 1.0f, "(%3.1f, %3.1f, %3.1f)", direction[0], direction[1], direction[2]);
	renderBitmapString(650, 75, 0.0f, 1.0f, 1.0f, "(%3.1f, %3.1f)", angleX, angleY);
}

Matrix Camera::getRotationMatrix()
{
	return prod(rollMatrix(angleY), yawMatrix(angleX));
}
