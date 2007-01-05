#include "stdafx.h"

#include "schedule.hpp"
#include "order.hpp"
#include "tabusearch.hpp"

using namespace std;

int call_count = 0;
int found = 0;
int app = 1;
boost::timer timer;
const double time_limit = 2.0;

int approx1(Flowshop&, Order& p)
{
	int m1_begin = p.time_passed(0);
	int m2_begin = p.time_passed(1);
	int m1 = m1_begin + p.time_left(0) + p.offlines_sum();
	int m2 = m2_begin + p.time_left(1);
	return max(m1,m2);
}

int approx2(Flowshop&, Order& p)
{
	int m1_begin = p.time_passed(0);
	int m2_begin = p.m2_start(m1_begin);
	int m1 = m1_begin + p.time_left(0) + p.offlines_sum() + p.shortest_left(1) + p.nowait_shift();
	int m2 = m2_begin + p.time_left(1);
	return max(m1,m2);
}

int approx3(Flowshop&, Order& p)
{
	int m1_begin = p.time_passed(0);
	int m2_begin = p.m2_start(m1_begin);
	int m1 = m1_begin + p.time_left(0) + p.offlines_sum() + p.shortest_left(1) + p.nowait_shift();
	int m2 = m2_begin + p.time_left(1);
	return max(m1,m2);
}

void branch(Flowshop& f, Order& p, Result& best)
{
	if (timer.elapsed() > time_limit)
		return;

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
	int init = 2, test;
	
	if (argc == 4)
	{
		init = atoi(argv[1]);
		app = atoi(argv[2]);
		test = atoi(argv[3]);
	}
	
	Flowshop f;
	cin >> f;

	Order p(f);
	
	switch (init)
	{
		case 1: p.init_sort(); break;
		case 2: p.init_greedy(); break;
		case 3: p.init_tabu(); break;
	}
	double init_time = timer.elapsed();
		
	Result best;
	best.cmax = numeric_limits<int>::max();
	
	timer.restart();
	branch(f,p,best);
	double time = timer.elapsed();

	if (time > time_limit)
	{
		cerr << "Time limit exceeded." << endl;
		return 0;
	}

	cout << f;
	cout << best.cmax << endl;
	cout << schedule(f, best.order);
	
	//cerr << best.cmax << endl;
	//cerr << "Calls: " << call_count << endl;
	//cerr << "Best found at: " << found << endl;
	//cerr << "Calls after best found: " << call_count-found << endl;
	//cerr << "Percentage of all calls: " << 100.0*(call_count-found)/call_count << endl;
	//cerr << "Time: " << time << endl;
	cerr << f.offlines.size()-2 << "," << f.tasks.size() << "," << test << "," << init << "," << app << "," << init_time << "," << time << "," << init_time+time << "," << call_count << "," << found << endl;
	
	return 0;
}
