#include "md3_frame.hpp"

#include <iostream>

void md3_frame::read(std::istream& input)
{
	binary_read(input, header);

#ifdef _DEBUG
	std::cerr << "Frame name: " << header.name << std::endl;
#endif
}
