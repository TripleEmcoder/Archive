#pragma once
#include <boost/numeric/ublas/vector.hpp>

class camera
{
public:
	enum axis {AXIS_X, AXIS_Y};
	camera(double eye_x, double eye_y, double eye_z, double angle_x, double angle_y);
	~camera(void);
	void draw();
	void rotate(double x, double y);
	void move(axis a, double speed);
private:
	typedef boost::numeric::ublas::c_vector<double, 3> c_vector;
	c_vector eye;
	double axis_x, axis_y;
	double init_angle_x, init_angle_y, angle_x, angle_y;
	int timebase;
	c_vector calculate_direction(double angle_x, double angle_y);
	void normalize_angle(double& angle);
};
