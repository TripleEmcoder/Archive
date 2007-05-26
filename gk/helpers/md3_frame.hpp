#ifndef OBJECTS_MD3_FRAME_HPP
#define OBJECTS_MD3_FRAME_HPP

#include "md3_common.hpp"

struct md3_vector
{
	float x;
	float y;
	float z;
};

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

class istream;

class md3_frame
{
public:
	void read(std::istream& input);
	
private:
	md3_frame_header header;
};

#endif //OBJECTS_MD3_FRAME_HPP