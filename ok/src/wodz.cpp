#include "data.hpp"
#include "common.hpp"

#include <iostream>
#include <algorithm>
#include <iterator>
using namespace std;

int main()
{
	Flowshop f;
	cin >> f;
	cout << f;	

	vector<int> p;
	copy(istream_iterator<int>(cin), istream_iterator<int>(), back_inserter(p));
	//cout << p;

	FlowshopSchedule fs = schedule(f, p);
	cout << fs.tasks[p.back()].periods[1][0].stop << endl;
	cout << fs;
	
	int sum = 0;

	for (int i=0; i<p.size(); i++)
		sum += fs.tasks[i].periods[1][0].stop;
	
	cout << sum << endl;
	verify(f, fs);
	
	return 0;
}
