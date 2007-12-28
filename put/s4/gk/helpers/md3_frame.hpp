#ifndef HELPERS_MD3_FRAME_HPP
#define HELPERS_MD3_FRAME_HPP

#include "md3_common.hpp"

/*
VEC3  MIN_BOUNDS   First corner of the bounding box.
VEC3  MAX_BOUNDS   Second corner of the bounding box.
VEC3  LOCAL_ORIGIN Local origin, usually (0, 0, 0).
F32   RADIUS       Radius of bounding sphere.
U8*16 NAME         Name of Frame. ASCII character string, NUL-terminated (C-style).
*/

struct md3_frame_header
{
	md3_vector lower;
	md3_vector upper;
	md3_vector origin;
	float radius;
	char name[16];
};

class md3_frame
{
public:
	void read(std::istream& input);
	
private:
	md3_frame_header header;
};

#endif //HELPERS_MD3_FRAME_HPP
