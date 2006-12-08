#include "stdafx.h"

#include "schedule.hpp"
#include "order.hpp"
#include <boost/date_time/posix_time/posix_time.hpp>


using namespace std;
using namespace boost::posix_time;


int call_count = 0;
int found = 0;
int app = 1;

struct Result
{
	int cmax;
	vector<int> order;
	bool operator<(const Result& a)	{ return cmax < a.cmax; }
};

int approx1(Flowshop& f, Order& p)
{
	int m1_begin = p.time_passed(0);
	int m2_begin = max(p.time_passed(1), m1_begin + p.shortest_left(0));
	int m1 = m1_begin + p.time_left(0) + p.offlines() + p.shortest_left(1);
	int m2 = m2_begin + p.time_left(1);
	return max(m1,m2);
}

int approx2(Flowshop& f, Order& p)
{
	int m1_begin = max(p.time_passed(0), p.soonest_left());
	int m2_begin = max(p.time_passed(1), m1_begin + p.shortest_left(0));
	int m1 = m1_begin + p.time_left(0) + p.offlines() + p.shortest_left(1);
	int m2 = m2_begin + p.time_left(1);
	return max(m1,m2);
}

int approx3(Flowshop& f, Order& p)
{
	int m1_begin = p.time_passed(0);
	int m2_begin = max(p.time_passed(1), m1_begin + p.shortest_left(0));
	int m1 = m1_begin + p.time_left(0) + p.offlines()+ p.shortest_left(1);
	int m2 = m2_begin + p.time_left(1);
	return max(m1,m2);
}

void branch(Flowshop& f, Order& p, Result& best)
{
	call_count++;

	if (p.tasks_size() == f.tasks.size())
	{
		if (p.time_passed(1) < best.cmax)
		{
			best.cmax = p.time_passed(1);
			best.order = vector<int>(p.tasks_begin(), p.tasks_end());
			found = call_count;
		}
	}
	else
	{
		int cmax;
		switch (app)
		{
			case 1:
				cmax = approx1(f,p);
				break;
			case 2:
				cmax = approx2(f,p);
				break;
			case 3:
				cmax = approx3(f,p);
				break;
			default:
				cmax = approx1(f,p);
		}
	
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
	int start, finish;
	if (argc == 2)
		app = atoi(argv[1]);
	
	Flowshop f;
	cin >> f;

	start = microsec_clock::local_time().time_of_day().total_milliseconds();

	Order p(f);
	p.init_greedy();
		
	Result best;
//	best.cmax = numeric_limits<int>::max();
	best.cmax = 999999999;

	branch(f,p,best);

	finish = microsec_clock::local_time().time_of_day().total_milliseconds();

	cout << f;
	cout << best.cmax << endl;
	cout << schedule(f, best.order);
	
	cerr << best.cmax << endl;
	cerr << "Calls: " << call_count << endl;
	cerr << "Best found at: " << found << endl;
	cerr << "Time: " << (finish-start) << endl;

	return 0;
}

