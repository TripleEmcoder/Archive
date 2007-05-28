#include "Camera.hpp"

#include "opengl.hpp"

const float ANG2RAD = 3.1416f / 180.0f;

Camera::Camera(float eyeX, float eyeY, float eyeZ, float x, float y)
{
	angleX = angleY = 0;
	matrix(3,0) = eyeX;
	matrix(3,1) = eyeY;
	matrix(3,2) = eyeZ;
	rotate(x, y);
}

Camera::~Camera(void)
{
}

void Camera::rotate(float x, float y)
{
	angleX += x;
	angleY += y;
	if (angleY >= 89.0f * ANG2RAD)
		angleY = 89.0f * ANG2RAD;
	if (angleY <= -89.0f * ANG2RAD)
		angleY = -89.0f * ANG2RAD;
	Vector position = matrix_row<Matrix4x4>(matrix, 3);
	matrix = prod(rollMatrix(angleY), yawMatrix(angleX));
	setPosition(position);
}

void Camera::set() const
{
	const Vector& eye = matrix_row<Matrix4x4>(matrix, 3);
	const Vector& front = matrix_row<Matrix4x4>(matrix, 0);
	Vector center = eye + front;		
	gluLookAt(eye[0], eye[1], eye[2], center[0], center[1], center[2], 0, 1, 0);
	calculatePlanes();
}

void Camera::draw(const state& state) const
{
	const Vector& eye = matrix_row<Matrix4x4>(matrix, 3);
	const Vector& front = matrix_row<Matrix4x4>(matrix, 0);
	write(650, 35, "(%3.1f, %3.1f, %3.1f)", eye[0], eye[1], eye[2]);
	write(650, 55, "(%3.1f, %3.1f, %3.1f)", front[0], front[1], front[2]);
	write(650, 75, "(%3.1f, %3.1f)", angleX, angleY);
}

void Camera::setPosition(const Vector& e)
{
	matrix_row<Matrix4x4>(matrix, 3) = e;
}

Vector Camera::getPosition() const
{
	return matrix_row<Matrix4x4>(matrix, 3);
}


float Camera::getAngleX() const
{
	return angleX;
}

float Camera::getAngleY() const
{
	return angleY;
}

void Camera::calculatePlanes() const
{
	const Vector& front = matrix_row<Matrix4x4>(matrix, 0);
	const Vector& up = matrix_row<Matrix4x4>(matrix, 1);
	const Vector& right = matrix_row<Matrix4x4>(matrix, 2);
	const Vector& position = matrix_row<Matrix4x4>(matrix, 3);
	
	Vector a, point;

	Vector nearCenter = position + front * nearDistance;
	Vector farCenter = position + front * farDistance;

	planes[NEAR_PLANE].normal = front;
	planes[NEAR_PLANE].distance = inner_prod(planes[NEAR_PLANE].normal, nearCenter);
	
	planes[FAR_PLANE].normal = -front;
	planes[FAR_PLANE].distance = inner_prod(planes[FAR_PLANE].normal, farCenter);
	
	a = (farCenter + up * farHeigth) - position;
	a /= norm_2(a);	
	planes[TOP_PLANE].normal = cross_prod(a, right);
	planes[TOP_PLANE].distance = inner_prod(planes[TOP_PLANE].normal, position);
	
	a = (farCenter - up * farHeigth) - position;
	a /= norm_2(a);	
	planes[BOTTOM_PLANE].normal = cross_prod(right, a);
	planes[BOTTOM_PLANE].distance = inner_prod(planes[BOTTOM_PLANE].normal, position);

	a = (farCenter - right * farWidth) - position;
	a /= norm_2(a);	
	planes[LEFT_PLANE].normal = cross_prod(a, up);
	planes[LEFT_PLANE].distance = inner_prod(planes[LEFT_PLANE].normal, position);

	a = (farCenter + right * farWidth) - position;
	a /= norm_2(a);	
	planes[RIGHT_PLANE].normal = cross_prod(up, a);
	planes[RIGHT_PLANE].distance = inner_prod(planes[RIGHT_PLANE].normal, position);
}

void Camera::setCameraInternals(float angle, float ratio, float nearD, float farD) 
{
	// store the information
	this->ratio = ratio;
	this->angle = angle;
	this->nearDistance = nearD;
	this->farDistance = farD;

	// compute width and height of the near and far plane sections
	float tang = (float)tan(angle * ANG2RAD * 0.5);
	nearHeigth = nearDistance * tang;
	nearWidth = nearHeigth * ratio; 
	farHeigth = farDistance * tang;
	farWidth = farHeigth * ratio;
}

bool Camera::isVisible(const int mins[3], const int maxs[3]) const
{
	for (int i = 0; i < 6; ++i)
	{
		boost::numeric::ublas::c_vector<int, 4> p;
		for (int j = 0; j < 3; ++j)
			p[j] = (planes[i].normal[j] >= 0) ? maxs[j] : mins[j];
		if (inner_prod(planes[i].normal, p) - planes[i].distance < 0)
			return false;
	}
	return true;
}

