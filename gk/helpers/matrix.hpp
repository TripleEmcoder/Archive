#ifndef HELPERS_MATRIX_HPP
#define HELPERS_MATRIX_HPP

#include <boost/numeric/ublas/matrix.hpp>

class vertex;

//macierz transformacji przestrzennych
class matrix
{
public:
	matrix();
	
	const float* row_major_data() const;
	const float* column_major_data() const;

	void translate(const vertex& description);
	void rotate(const vertex& description);
	void scale(const vertex& description);
	void compose(const matrix& composition);

private:
	typedef boost::numeric::ublas::matrix<float> temporary_type;
	typedef boost::numeric::ublas::matrix<float, boost::numeric::ublas::row_major> row_major_type;
	typedef boost::numeric::ublas::matrix<float, boost::numeric::ublas::column_major> column_major_type;
	row_major_type row_major;
	column_major_type column_major;
};

#endif //HELPERS_MATRIX_HPP
