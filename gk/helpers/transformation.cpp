#include "transformation.hpp"

#include "vertex.hpp"

using boost::numeric::ublas::matrix;
using boost::numeric::ublas::identity_matrix;
using boost::numeric::ublas::prod;

transformation::transformation()
:
	row_major(identity_matrix<float>(4)),
	column_major(identity_matrix<float>(4))
{
}

const float* transformation::row_major_data() const
{
	return row_major.data().begin();
}

const float* transformation::column_major_data() const
{
	return column_major.data().begin();
}

void transformation::translate(const vertex& axes)
{
	matrix<float> local(identity_matrix<float>(4));

	local(3, 0) = axes.x;
	local(3, 1) = axes.y;
	local(3, 2) = axes.z;

	row_major = prod(row_major, local);
	column_major = prod(column_major, local);
}

void transformation::rotate(const vertex& axes)
{
	matrix<float> pitch(identity_matrix<float>(4));
	pitch(1,1) = cos(axes.x);
	pitch(1,2) = -sin(axes.x);
	pitch(2,1) = sin(axes.x);
	pitch(2,2) = cos(axes.x);

	matrix<float> yaw(identity_matrix<float>(4));
	yaw(0,0) = cos(axes.y);
	yaw(0,2) = -sin(axes.y);
	yaw(2,0) = sin(axes.y);
	yaw(2,2) = cos(axes.y);

	matrix<float> roll(identity_matrix<float>(4));
	roll(0,0) = cos(axes.z);
	roll(0,1) = -sin(axes.z);
	roll(1,0) = sin(axes.z);
	roll(1,1) = cos(axes.z);

	//matrix<float> part = prod(pitch, yaw);
	//matrix<float> local = prod(part, roll);
	matrix<float> local = yaw;

	row_major = prod(row_major, local);
	column_major = prod(column_major, local);
}
