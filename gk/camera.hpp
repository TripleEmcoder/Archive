#pragma once
#include <boost/numeric/ublas/vector.hpp>

class camera
{
public:
	enum direction { forward, backward, left, right };
	camera(double eye_x, double eye_y, double eye_z, double angle_x, double angle_y);
	~camera(void);
	void draw();
	void rotate(double x, double y);
	void move(direction dir, double speed);
private:
	typedef boost::numeric::ublas::c_vector<double, 3> c_vector;
	c_vector eye;
	direction dir;
	double speed;
	double init_angle_x, init_angle_y, angle_x, angle_y;
	c_vector calculate_direction();
	double normalize_angle(double angle);
};
