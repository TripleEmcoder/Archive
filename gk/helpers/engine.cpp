#include "engine.hpp"

float radians(float degrees)
{
	return degrees * 3.1416f / 180.0f;
}

float degrees(float radians)
{
	return radians / 3.1416f * 180.0f;
}
