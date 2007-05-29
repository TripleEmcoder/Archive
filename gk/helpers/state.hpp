#ifndef HELPERS_STATE_HPP
#define HELPERS_STATE_HPP

#include <vector>

#include <boost/utility.hpp>

class Camera;

class state : private boost::noncopyable
{
public:
	const Camera* camera;
	std::vector<bool> monostables;
	std::vector<bool> bistables;
};

#endif //HELPERS_STATE_HPP
