#include "data.hpp"
#include "schedule.hpp"
#include "verify.hpp"

#include <iostream>
using namespace std;

int main()
{
	Flowshop f;
	cin >> f;
	cout << f;	

	vector<int> p;
	cin >> p;

	FlowshopSchedule fs = schedule(f, p);
	cout << fs.tasks[p.back()].periods[1][0].stop << endl;
	cout << fs;
	
	int sum = 0;

	for (size_t i=0; i<p.size(); i++)
		sum += fs.tasks[i].periods[1][0].stop;
	
	cout << sum << endl;

	verify(f, fs);
	
	return 0;
}
