#pragma once
#include "stdafx.h"
#include "tabusearch.hpp"
#include "schedule.hpp"

using namespace std;

int main(int argc, char* argv[])
{
	if (argc != 5)
		return 1;

	srand((unsigned)time(0));

	Flowshop f;
	cin >> f;

	Result result = tabusearch(f, atoi(argv[1]), atoi(argv[2]), atoi(argv[3]), atoi(argv[4]));

	cout << f;
	cout << result.cmax << endl;
	cout << schedule(f, result.order);

	cerr << endl << result.cmax << endl;

	return 0;
}
