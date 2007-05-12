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
	axis_x = axis_y = 0;
	timebase = glutGet(GLUT_ELAPSED_TIME);
}

camera::~camera(void)
{
}

void camera::rotate(double x, double y)
{
	angle_x = init_angle_x + x;
	angle_y = init_angle_y + y;
}

void camera::draw()
{
	c_vector direction = calculate_direction(angle_x, angle_y);
	c_vector strafe_direction = calculate_direction(angle_x + 90, 0);
	c_vector center = eye + direction;
		
	gluLookAt(eye[0], eye[1], eye[2], center[0], center[1], center[2], 0, 1, 0);

	int time = glutGet(GLUT_ELAPSED_TIME);

	double scale = (axis_x != 0.0 && axis_y != 0.0) ? 1.0/sqrt(2.0f) : 1;
	
	eye += (direction * axis_x + strafe_direction * axis_y) * scale *(double)(time - timebase) / 1000;
	
	timebase = time;
}

void camera::move(axis a, double speed)
{
	if (a == AXIS_X)
		axis_x = speed;
	else if (a == AXIS_Y)
		axis_y = speed;
}


camera::c_vector camera::calculate_direction(double angle_x, double angle_y)
{
	c_vector result;
	normalize_angle(angle_x);
	normalize_angle(angle_y);
	result[0] = cos(angle_y) * cos(angle_x);
	result[1] = sin(angle_y);
	result[2] = cos(angle_y) * sin(angle_x);
	return result;
}

void camera::normalize_angle(double& angle)
{
	while (angle < -180)
		angle += 360;
	while (angle > 180)
		angle -= 360;	
	angle *= 3.141592653589793 / 180.0;
}
