#pragma once

#include "data.hpp"

struct Result
{
	int cmax;
	vector<int> order;
	bool operator<(const Result& a)	{ return cmax < a.cmax; }
};

Result tabusearch(Flowshop& f, int tabus, int chances, int resets, int distance);
