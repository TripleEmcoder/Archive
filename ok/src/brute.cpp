#include "data.hpp"
#include "common.hpp"

#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
	Flowshop f;
	cin >> f;

	vector<int> p(2);
	p[0] = 0;
	p[1] = 1;

	do 
	{	
		FlowshopSchedule fs(f);
		cout << schedule(f, fs, p) << endl;
		cout << fs;
	}
	while (next_permutation(p.begin(), p.end()));

	return 0;
}
