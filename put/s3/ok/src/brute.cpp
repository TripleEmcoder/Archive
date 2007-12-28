#include "data.hpp"
#include "schedule.hpp"
#include "verify.hpp"

#include <iostream>
#include <algorithm>
#include <limits>
using namespace std;

int main()
{
	Flowshop f;
	cin >> f;

	vector<int> p(f.tasks.size());
	for (size_t i=0; i<p.size(); i++)
		p[i] = i;

	int cmax_min = numeric_limits<int>().max();
	vector<int> p_min;
	int count = 0;

	do 
	{	
		int cmax = simulate(f, p);

		if (cmax < cmax_min)
		{
			cmax_min = cmax;
			p_min = p;
			count = 1;
		}
		else if (cmax == cmax_min)
		{
			count++;
		}

		//weryfikacja dla kazdej permutacji
		FlowshopSchedule fs = schedule(f, p);

		try
		{
			verify(f, fs);
		}
		catch (const char* message)
		{
			cout << "!!!!!" << endl;
			cout << message << endl;
			cout << "!!!!!" << endl;
			cout << f;
			cout << cmax << endl;
			cout << fs;
			return 1;
		}
	}
	while (next_permutation(p.begin(), p.end()));

	cout << f;	
	cout << cmax_min << endl;
	cout << schedule(f, p_min);

	cerr << cmax_min;

	return 0;
}
