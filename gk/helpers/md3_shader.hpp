#ifndef OBJECTS_MD3_SHADER_HPP
#define OBJECTS_MD3_SHADER_HPP

#include "md3_common.hpp"

/*
U8*MAX_QPATH NAME         Pathname of shader in the PK3. ASCII character string, NUL-terminated (C-style). Current value of MAX_QPATH is 64.
S32          SHADER_INDEX Shader index number. No idea how this is allocated, but presumably in sequential order of definiton.
*/

struct md3_shader_header
{
	char name[MD3_MAX_NAME];
	int index;
};

class md3_shader
{
public:
	void read(std::istream& input);

private:
	md3_shader_header header;
};

#endif //OBJECTS_MD3_SHADER_HPP
