#include "matrix.hpp"
#include "vertex.hpp"
#include "engine.hpp"

using boost::numeric::ublas::identity_matrix;
using boost::numeric::ublas::prod;

matrix::matrix()
:
	row_major(identity_matrix<float>(4)),
	column_major(identity_matrix<float>(4))
{
}

const float* matrix::row_major_data() const
{
	return row_major.data().begin();
}

const float* matrix::column_major_data() const
{
	return column_major.data().begin();
}

void matrix::translate(const vertex& description)
{
	temporary_type temporary(identity_matrix<float>(4));

	temporary(3,0) = description.x;
	temporary(3,1) = description.y;
	temporary(3,2) = description.z;

	row_major = prod(temporary, row_major);
	column_major = prod(temporary, column_major);
}

void matrix::rotate(const vertex& description)
{
	temporary_type pitch(identity_matrix<float>(4));
	pitch(1,1) = cos(radians(description.x));
	pitch(1,2) = -sin(radians(description.x));
	pitch(2,1) = sin(radians(description.x));
	pitch(2,2) = cos(radians(description.x));

	temporary_type yaw(identity_matrix<float>(4));
	yaw(0,0) = cos(radians(description.y));
	yaw(0,2) = -sin(radians(description.y));
	yaw(2,0) = sin(radians(description.y));
	yaw(2,2) = cos(radians(description.y));

	temporary_type roll(identity_matrix<float>(4));
	roll(0,0) = cos(radians(description.z));
	roll(0,1) = -sin(radians(description.z));
	roll(1,0) = sin(radians(description.z));
	roll(1,1) = cos(radians(description.z));

	temporary_type temporary = identity_matrix<float>(4);
	temporary = prod(temporary, roll);
	temporary = prod(temporary, yaw);
	temporary = prod(temporary, pitch);

	row_major = prod(temporary, row_major);
	column_major = prod(temporary, column_major);
}

void matrix::scale(const vertex& description)
{
	temporary_type temporary(identity_matrix<float>(4));

	temporary(0,0) = description.x;
	temporary(1,1) = description.y;
	temporary(2,2) = description.z;

	row_major = prod(temporary, row_major);
	column_major = prod(temporary, column_major);
}

void matrix::compose(const matrix& composition)
{
	row_major = prod(composition.row_major, row_major);
	column_major = prod(composition.column_major, column_major);
}
