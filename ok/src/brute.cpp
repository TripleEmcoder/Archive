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
		schedule(f, fs, p);
		cout << fs;
		cout << "----" << endl;
	}
	while (next_permutation(p.begin(), p.end()));

	return 0;
}
