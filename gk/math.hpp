#pragma once
#pragma warning(push)
#pragma warning(disable : 4267; disable : 4244)
#include <boost/numeric/ublas/vector.hpp>
#include <boost/numeric/ublas/matrix.hpp>
#include <boost/numeric/ublas/matrix_proxy.hpp>
#pragma warning(pop)

using namespace boost::numeric::ublas;
typedef c_matrix<float, 4, 4> Matrix;
typedef c_vector<float, 4> Vector;

inline Matrix pitchMatrix(float angle) // X-Axis
{
	Matrix result(identity_matrix<float>(4));
	result(1,1) = cos(angle);
	result(1,2) = -sin(angle);
	result(2,1) = sin(angle);
	result(2,2) = cos(angle);
	return result;
}

inline Matrix yawMatrix(float angle) // Y-Axis
{
	Matrix result(identity_matrix<float>(4));
	result(0,0) = cos(angle);
	result(0,2) = -sin(angle);
	result(2,0) = sin(angle);
	result(2,2) = cos(angle);
	return result;
}

inline Matrix rollMatrix(float angle) // Z-Axis
{
	Matrix result(identity_matrix<float>(4));
	result(0,0) = cos(angle);
	result(0,1) = -sin(angle);
	result(1,0) = sin(angle);
	result(1,1) = cos(angle);
	return result;
}

inline Matrix translationMatrix(float x, float y, float z)
{
	Matrix result(identity_matrix<float>(4));
	result(3,0) = x;
	result(3,1) = y;
	result(3,2) = z;
	return result;
}

inline Matrix rotationMatrix(float angleX, float angleY, float angleZ)
{
	Matrix m = prod(yawMatrix(angleY), rollMatrix(angleZ));
	return prod(pitchMatrix(angleX), m);
}

inline Vector rotate(const Vector& vec, float angleX, float angleY, float angleZ)
{
	return prod(vec, rotationMatrix(angleX, angleY, angleZ));
}

inline Vector createVector(float x, float y, float z, float w = 1)
{
	Vector vec;
	vec[0] = x;
	vec[1] = y;
	vec[2] = z;
	vec[3] = w;
	return vec;
}

inline Vector cross_prod(const Vector& a, const Vector& b)
{
	return createVector(-a[2] * b[1] + a[1] * b[2], a[2] * b[0] - a[0] * b[2], -a[1] * b[0] + a[0] * b[1], 0);
}




	