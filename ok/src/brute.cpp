#include "data.hpp"
#include "common.hpp"

#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
	Flowshop f;
	cin >> f;

	vector<int> p(f.tasks.size());
	for (int i=0; i<p.size(); i++)
		p[i] = i;


	p[0] = 0;
	p[1] = 7;
	p[2] = 5;
	p[3] = 2;
	p[4] = 1;
	p[5] = 6;
	p[6] = 4;
	p[7] = 3;


	int cmax_min = numeric_limits<int>().max();
	FlowshopSchedule fs_min(f);

	do 
	{	
		FlowshopSchedule fs(f);
		int cmax = schedule(f, fs, p);

		if (cmax < cmax_min)
		{
			cmax_min = cmax;
			fs_min = fs;
		}

		if (!verify(f, fs))
		{
			cerr << "!verify" << endl;
			cout << cmax << endl;
			cout << fs;
			return 1;
		}

		break;
	}
	while (next_permutation(p.begin(), p.end()));
	
	cout << cmax_min << endl;
	cout << fs_min;

	return 0;
}
