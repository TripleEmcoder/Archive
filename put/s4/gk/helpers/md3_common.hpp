#ifndef HELPERS_MD3_COMMON_HPP
#define HELPERS_MD3_COMMON_HPP

const float MD3_SCALE = 1.0f / 1800.0f;
const float MD3_FPS = 2.0f;
const float MD3_PI = 3.14159265f;

const int MD3_MAGIC = 860898377;
const int MD3_VERSION = 15;
const int MD3_MAX_NAME = 64;

#include <istream>

template<typename T>
void binary_read(std::istream& input, T& item)
{
	input.read((char*)&item, sizeof(item));
}

struct md3_vector
{
	float x;
	float y;
	float z;
};

#endif //HELPERS_MD3_COMMON_HPP
