#include "camera.hpp"

#include <windows.h>
#include <GL/gl.h>
#include <GL/glu.h>
#include <GL/glut.h>

camera::camera(double eye_x, double eye_y, double eye_z, double angle_x, double angle_y) 
{
	eye[0] = eye_x;
	eye[1] = eye_y;
	eye[2] = eye_z;
	init_angle_x = angle_x;
	init_angle_y = angle_y;
	dir = direction::forward;
	speed = 0;
}

camera::~camera(void)
{
}

void camera::rotate(double x, double y)
{
	angle_x = normalize_angle(init_angle_x + x);
	angle_y = normalize_angle(init_angle_y + y);
}

void camera::draw()
{
	c_vector direction = calculate_direction();
	c_vector center = eye + direction;
		
	//gluLookAt(eye[0], eye[1], eye[2], center[0], center[1], center[2], up[0], up[1], up[2]);
	gluLookAt(eye[0], eye[1], eye[2], center[0], center[1], center[2], 0, 1, 0);

	switch (dir)
	{
	case forward:
		eye += direction * speed;
		break;
	case backward:
		eye -= direction * speed;
		break;
	}
}

void camera::move(direction d, double s)
{
	dir = d;
	speed = s;
}


camera::c_vector camera::calculate_direction()
{
	c_vector result;
	result[0] = cos(angle_y) * cos(angle_x);
	result[1] = sin(angle_y);
	result[2] = cos(angle_y) * sin(angle_x);
	return result;
}

double camera::normalize_angle(double angle)
{
	while (angle < -180)
		angle += 360;
	while (angle > 180)
		angle -= 360;	
	return angle * 3.141592653589793 / 180.0;
}
