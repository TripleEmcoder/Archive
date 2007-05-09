#include <iostream>
#include <fstream>

#include "map.hpp"

int main()
{
	std::ifstream ifs("map.xml");

	map m;
	ifs >> m;
	std::cout << m;

	return 0;
} 