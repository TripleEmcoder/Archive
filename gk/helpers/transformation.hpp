#ifndef HELPERS_TRANSFORMATION_HPP
#define HELPERS_TRANSFORMATION_HPP

#include <boost/numeric/ublas/matrix.hpp>

class vertex;

class transformation
{
public:
	transformation();
	
	const float* row_major_data() const;
	const float* column_major_data() const;

	void translate(const vertex& axes);
	void rotate(const vertex& axes);

private:
	boost::numeric::ublas::matrix<float, boost::numeric::ublas::row_major> row_major;
	boost::numeric::ublas::matrix<float, boost::numeric::ublas::column_major> column_major;
};

#endif //HELPERS_TRANSFORMATION_HPP
