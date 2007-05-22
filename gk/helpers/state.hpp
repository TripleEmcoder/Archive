#ifndef HELPERS_STATE_HPP
#define HELPERS_STATE_HPP

#include <boost/utility.hpp>

class Camera;

class state : private boost::noncopyable
{
public:
	const Camera* camera;
};

#endif //HELPERS_STATE_HPP
