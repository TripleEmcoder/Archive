#pragma once
#include <boost/numeric/ublas/vector.hpp>
#include <boost/numeric/ublas/matrix.hpp>
#include <boost/numeric/ublas/matrix_proxy.hpp>

using namespace boost::numeric::ublas;
typedef c_matrix<float, 4, 4> Matrix;
typedef c_vector<float, 4> Vector;

inline Matrix rollMatrix(float angle)
{
	Matrix result(identity_matrix<float>(4));
	result(0,0) = cos(angle);
	result(0,1) = -sin(angle);
	result(1,0) = sin(angle);
	result(1,1) = -cos(angle);
	return result;
}

inline Matrix yawMatrix(float angle)
{
	Matrix result(identity_matrix<float>(4));
	result(0,0) = cos(angle);
	result(0,2) = -sin(angle);
	result(2,0) = sin(angle);
	result(2,2) = -cos(angle);
	return result;
}

inline Matrix pitchMatrix(float angle)
{
	Matrix result(identity_matrix<float>(4));
	result(1,1) = cos(angle);
	result(1,2) = -sin(angle);
	result(2,1) = sin(angle);
	result(2,2) = -cos(angle);
	return result;
}
	