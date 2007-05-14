#include <boost/archive/xml_iarchive.hpp>
#include <boost/archive/xml_oarchive.hpp>
#include <boost/serialization/nvp.hpp>

#include "map.hpp"
#include "../math.hpp"

std::istream& operator>> (std::istream& is, map& m)
{
	boost::archive::xml_iarchive ia(is);
	ia >> boost::serialization::make_nvp("map", m);

	return is;
}

std::ostream& operator<< (std::ostream& os, const map& m)
{
	boost::archive::xml_oarchive oa(os);
	oa << boost::serialization::make_nvp("map", m);

	return os;
}

#include <windows.h>
#include <GL/gl.h>
#include <GL/glaux.h>

void map::draw() const
{
	group::draw();

	glColor3d(1, 1, 1);
	auxSolidSphere(0.2);
}

void map::build(NewtonWorld *world) const
{
	NewtonCollision* collision = NewtonCreateTreeCollision(world, NULL);
	NewtonTreeCollisionBeginBuild(collision);

	group::build(collision);

	NewtonTreeCollisionEndBuild(collision, 1);

	NewtonBody* body = NewtonCreateBody(world, collision);

	// release the collision tree (this way the application does not have to do book keeping of Newton objects
	NewtonReleaseCollision(world, collision);

	Matrix location = identity_matrix<float>(4);

	matrix_row<Matrix> row(location, 3);
	row[0] = 0;
	row[1] = 0;
	row[2] = 0;

	// set the global position of this body
	NewtonBodySetMatrix(body, location.data());
}
