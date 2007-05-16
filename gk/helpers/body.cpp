#include "body.hpp"
#include "object.hpp"
#include "world.hpp"
#include "transformation.hpp"

#include <boost/lambda/bind.hpp>
using boost::lambda::bind;
using boost::lambda::_1;

void body::compile()
{
	NewtonCollision* collision = NewtonCreateNull(root().newton());
	
	_newton.reset(NewtonCreateBody(root().newton(), collision),
		bind(NewtonDestroyBody, root().newton(), _1));

	NewtonReleaseCollision(root().newton(), collision);

	NewtonBodySetMatrix(newton(), composition().row_major_data());
	NewtonBodySetUserData(newton(), this);
}

void body::draw() const
{
}

const NewtonBody* body::newton() const
{
	return _newton.get();
}
