#pragma once
#include <boost/numeric/ublas/vector.hpp>

class Camera
{
public:
	enum Axis {AXIS_X, AXIS_Y};
	Camera(double eyeX, double eyeY, double eyeZ, double angleX, double angleY);
	~Camera(void);
	void draw();
	void rotate(double x, double y);
	void move(Axis a, double speed);
private:
	typedef boost::numeric::ublas::c_vector<double, 3> c_vector;
	c_vector eye;
	double speed[2];
	double initAngleX, initAngleY, angleX, angleY;
	int timebase;
	c_vector calculateDirection(double angleX, double angleY);
	void normalizeAngle(double& angle);
};
