#include "Camera.hpp"

#include <windows.h>
#include <GL/gl.h>
#include <GL/glu.h>
#include <GL/glut.h>

Camera::Camera(double eyeX, double eyeY, double eyeZ, double angleX, double angleY)
{
	eye[0] = eyeX;
	eye[1] = eyeY;
	eye[2] = eyeZ;
	initAngleX = angleX;
	initAngleY = angleY;
	this->angleX = angleX;
	this->angleY = angleY; 
	speed[AXIS_X] = speed[AXIS_Y] = 0;
	timebase = glutGet(GLUT_ELAPSED_TIME);
}

Camera::~Camera(void)
{
}

void Camera::rotate(double x, double y)
{
	//angleX = initAngleX + x;
	//angleY = initAngleY + y;
	angleX += x;
	angleY += y;
}

void Camera::draw()
{
	c_vector direction = calculateDirection(angleX, angleY);
	c_vector strafeDirection = calculateDirection(angleX + 90, 0);
	c_vector center = eye + direction;
		
	gluLookAt(eye[0], eye[1], eye[2], center[0], center[1], center[2], 0, 1, 0);

	int time = glutGet(GLUT_ELAPSED_TIME);

	double scale = (speed[AXIS_X] != 0.0 && speed[AXIS_Y] != 0.0) ? 1.0/sqrt(2.0f) : 1;
	
	eye += (direction * speed[AXIS_Y] + strafeDirection * speed[AXIS_X]) * scale *(double)(time - timebase) / 1000;
	
	timebase = time;
}

void Camera::drawHUD()
{
	renderBitmapString(650, 35, "(%3.1f, %3.1f, %3.1f)", eye[0], eye[1], eye[2]);
	renderBitmapString(650, 55, "(%3.1f, %3.1f)", angleX, angleY);
}

void Camera::move(Axis a, double s)
{
	speed[a] = s;
}


Camera::c_vector Camera::calculateDirection(double angleX, double angleY)
{
	c_vector result;
	normalizeAngle(angleX);
	normalizeAngle(angleY);
	result[0] = cos(angleY) * cos(angleX);
	result[1] = sin(angleY);
	result[2] = cos(angleY) * sin(angleX);
	return result;
}

void Camera::normalizeAngle(double& angle)
{
	while (angle < -180)
		angle += 360;
	while (angle > 180)
		angle -= 360;	
	angle *= 3.141592653589793 / 180.0;
}
