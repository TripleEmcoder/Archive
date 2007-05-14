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
	renderBitmapString(650, 35, "(%3.1f, %3.1f, %3.1f)", eye[0], eye[1], eye[2]);
	renderBitmapString(650, 55, "(%3.1f, %3.1f, %3.1f)", direction[0], direction[1], direction[2]);
	renderBitmapString(650, 75, "(%3.1f, %3.1f)", angleX, angleY);
}

Vector Camera::calculateDirection(float angleX, float angleY)
{
	Vector result;
	normalizeAngle(angleX);
	normalizeAngle(angleY);
	result[0] = cos(angleY) * cos(angleX);
	result[1] = sin(angleY);
	result[2] = cos(angleY) * sin(angleX);
	return result;
}

void Camera::normalizeAngle(float& angle)
{
	while (angle < -180)
		angle += 360;
	while (angle > 180)
		angle -= 360;	
	angle *= 3.141592653589793 / 180.0;
}

Matrix Camera::getRotationMatrix()
{
	return prod(rollMatrix(angleY), yawMatrix(angleX));
}

Matrix Camera::getReversedRotationMatrix()
{
	return prod(-yawMatrix(angleX), -rollMatrix(angleY));
}
