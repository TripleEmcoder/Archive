#include "stdafx.h"

#include "schedule.hpp"
#include "order.hpp"
#include "tabusearch.hpp"

using namespace std;

int call_count = 0;
int found = 0;
int app;
boost::timer timer;

int approx0(Flowshop&, Order& p)
{
	return p.time_passed(1);
}

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
			case 0:
				cmax = approx0(f, p);
				break;
			case 1:
				cmax = approx1(f, p);
				break;
			case 2:
				cmax = approx2(f, p);
				break;
			case 3:
			default:
				cmax = approx3(f, p);
				break;
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
	int init = 3;
	
	if (argc == 3)
	{
		init = atoi(argv[1]);
		app = atoi(argv[2]);
	}
	else
	{
		cerr << "Zla liczba argumentow: " << argc << endl;
		return 1;
	}

	if (init < 1 || init > 3)
	{
		cerr << "Zla wartosc init: " << init << endl;
		return 1;
	}

	if (app < 0 || app > 3)
	{
		cerr << "Zla wartosc app: " << app << endl;
		return 1;
	}
	
	Flowshop f;
	cin >> f;

	Order p(f);
	
	Result best;
	
	switch (init)
	{
		case 1: best = p.init_sort(); break;
		case 2: best = p.init_greedy(); break;
		case 3: best = p.init_tabu(); break;
	}
	
	double init_time = timer.elapsed();
	
	timer.restart();
	branch(f, p, best);
	double time = timer.elapsed();

	cout << f;
	cout << best.cmax << endl;
	cout << schedule(f, best.order);
	
	cerr << call_count << "," << init_time << "," << time << "," << init_time+time << endl;
	
	return 0;
}
