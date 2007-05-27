#ifndef HELPERS_MATRIX_HPP
#define HELPERS_MATRIX_HPP

#pragma warning(push)
#pragma warning(disable : 4267; disable : 4244)
#include <boost/numeric/ublas/matrix.hpp>
#pragma warning(pop)

float degrees_to_radians(float degrees);
float radians_to_degrees(float radians);

class vertex;

//macierz transformacji przestrzennych
class matrix
{
public:
	matrix();
	
	float* row_major_data();
	const float* row_major_data() const;

	float* column_major_data();
	const float* column_major_data() const;

	void translate(const vertex& description);
	void rotate(const vertex& description);
	void scale(const vertex& description);
	void compose(const matrix& description);

private:
	typedef boost::numeric::ublas::matrix<float> temporary_type;
	typedef boost::numeric::ublas::matrix<float, boost::numeric::ublas::row_major> row_major_type;
	typedef boost::numeric::ublas::matrix<float, boost::numeric::ublas::column_major> column_major_type;

	row_major_type row_major;
	column_major_type column_major;
};

#endif //HELPERS_MATRIX_HPP
