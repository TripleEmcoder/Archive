#ifndef HELPERS_STATE_HPP
#define HELPERS_STATE_HPP

#include <map>

#include <boost/utility.hpp>

class Camera;

class state : private boost::noncopyable
{
public:
	state(const Camera& camera);

	const Camera& camera;
	std::map<int, int> settings;
};

const int LIGHTING_MODE = 0;

const int LIGHTING_MODE_LIGHTMAP = 0;
const int LIGHTING_MODE_VERTEX = 1;

#endif //HELPERS_STATE_HPP
