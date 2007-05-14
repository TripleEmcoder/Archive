#include <boost/archive/xml_iarchive.hpp>
#include <boost/archive/xml_oarchive.hpp>
#include <boost/serialization/nvp.hpp>

#include "world.hpp"
#include "engine.hpp"
#include "../math.hpp"

#include <algorithm>

#include <boost/lambda/lambda.hpp>
#include <boost/lambda/bind.hpp>

using boost::lambda::bind;
using boost::lambda::_1;

std::istream& operator>> (std::istream& is, world& world)
{
	boost::archive::xml_iarchive ia(is);
	ia >> boost::serialization::make_nvp("world", world);

	return is;
}

std::ostream& operator<< (std::ostream& os, const world& world)
{
	boost::archive::xml_oarchive oa(os);
	oa << boost::serialization::make_nvp("world", world);

	return os;
}

world::world()
: newton(NewtonCreate(NULL, NULL), NewtonDestroy)
{
}

void world::draw() const
{
	std::for_each(groups.begin(), groups.end(), bind(&object::draw, _1));

	glColor3d(1, 1, 1);
	auxSolidSphere(0.2);
}

void world::compile()
{
	root = this;
	std::for_each(groups.begin(), groups.end(), bind(&object::compile, _1, this));
	/*
	NewtonCollision* collision = NewtonCreateTreeCollision(world, NULL);
	NewtonTreeCollisionBeginBuild(collision);

	//group::build(collision);

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
	*/
}

const material* world::resolve(std::string name) const
{
	if (bindings.count(name))
		name = bindings.find(name)->second;

	else if (bindings.count("default"))
		name = bindings.find("default")->second;

	if (materials.count(name))
		return &materials.find(name)->second;

	static const material default(vertex(1, 0, 0));
	
	return &default;
}