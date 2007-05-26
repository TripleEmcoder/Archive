#include "md3_shader.hpp"

#include <iostream>

void md3_shader::read(std::istream& input)
{
	binary_read(input, header);

#ifdef _DEBUG
	std::cerr << "Shader name: " << header.name << std::endl;
#endif
}

std::string md3_shader::name() const
{
	return header.name;
}