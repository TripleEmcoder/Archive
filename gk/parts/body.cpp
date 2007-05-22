#include "body.hpp"
#include "object.hpp"
#include "world.hpp"
#include "matrix.hpp"

#include <boost/lambda/bind.hpp>
using boost::lambda::bind;
using boost::lambda::_1;

void body::compile()
{
	NewtonCollision* collision = NewtonCreateNull(root().newton());
	
	//_newton.reset(NewtonCreateBody(root().newton(), collision),
	//	bind(NewtonDestroyBody, root().newton(), _1));
	_newton = NewtonCreateBody(root().newton(), collision);

	NewtonReleaseCollision(root().newton(), collision);

	NewtonBodySetMatrix(newton(), composition().row_major_data());
	NewtonBodySetUserData(newton(), this);
}

void body::draw(const state& state) const
{
}

const NewtonBody* body::newton() const
{
	//return _newton.get();
	return _newton;
}
