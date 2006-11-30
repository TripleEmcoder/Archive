#include "stdafx.h"

#include "schedule.hpp"
#include "order.hpp"

using namespace std;

int call_count = 0;

struct Result
{
	int cmax;
	vector<int> order;
	bool operator<(const Result& a)	{ return cmax < a.cmax; }
};

void branch(Flowshop& f, Order& p, Result& best)
{
	call_count++;

	int cmax = max( p.time_passed(0)+p.time_left(0)+p.offlines(), p.time_passed(1)+p.time_left(1) );
	
	if (p.tasks_size() == f.tasks.size())
	{
		if (cmax < best.cmax)
		{
			best.cmax = cmax;
			best.order = vector<int>(p.tasks_begin(), p.tasks_end());
		}
	}
	else
	{
		for (VI i = p.left_begin(); i != p.left_end(); ++i)
		{
			if (cmax < best.cmax)
			{
				State s = p.getState();
				p.add(i);
				branch(f,p,best);
				p.remove(i);
				p.setState(s);
			}
			else
				break;
		}
	}
}

int main(int argc, char* argv[])
{
	Flowshop f;
	cin >> f;

	Order p(f);
	p.init_greedy();
		
	Result best;
	best.cmax = numeric_limits<int>::max();

	branch(f,p,best);

	cout << f;
	cout << best.cmax << endl;
	cout << schedule(f, best.order);
	
	cerr << best.cmax << endl;
	cerr << "Calls: " << call_count << endl;

	return 0;
}