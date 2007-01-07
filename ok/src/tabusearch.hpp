#pragma once

#include "data.hpp"

struct Result
{
	int cmax;
	vector<int> order;
};

bool operator<(const Result& a, const Result& b);

Result tabusearch(Flowshop& f, int tabus, int chances, int resets, int distance);
