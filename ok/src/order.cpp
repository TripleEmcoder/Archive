#include "stdafx.h"
#include "order.hpp"
#include "schedule.hpp"

struct TaskArrivalCmp
{
	vector<Task>& p;
	bool operator()(const int& a, const int& b)	{return p[a].arrival < p[b].arrival;}
	TaskArrivalCmp(vector<Task>& p): p(p) { };
};

struct TaskSumCmp
{
	vector<Task>& p;
	int x;
	bool operator()(const int& a, const int& b) { return p[a].sums[x] < p[b].sums[x];}
	TaskSumCmp(vector<Task>& p, int x): p(p), x(x) { };
};

Order::Order(Flowshop& f) :f(f)
{
	a.resize(f.tasks.size());
	sum[0] = 0;
	sum[1] = 0;
	int min_arrival = numeric_limits<int>::max();
	for (int i = 0; i < (int)a.size(); ++i)
	{
		a[i] = i;
		sum[0] += f.tasks[i].sums[0];
		sum[1] += f.tasks[i].sums[1];
		min_arrival = min(min_arrival,f.tasks[i].arrival);
	}
	time[0] = min_arrival;
	time[1] = 0;
	offline = f.offlines.begin();
	n = 0;
	line = a.begin();
}

void Order::add(VI i)
{
	simulate_task(f.tasks[*i], time, offline);
	sum[0] -= f.tasks[*i].sums[0];
	sum[1] -= f.tasks[*i].sums[1];
	swap(*line,*i);
	line++;
	n++;
}

void Order::remove(VI i)
{
	n--;
	line--;
	swap(*line,*i);
	sum[0] += f.tasks[*i].sums[0];
	sum[1] += f.tasks[*i].sums[1];
}

VI Order::tasks_begin()
{
	return a.begin();
}

VI Order::tasks_end()
{
	return line;
}

size_t Order::tasks_size()
{
	return n;
}

VI Order::left_begin()
{
	return line;
}

VI Order::left_end()
{
	return a.end();
}

size_t Order::left_size()
{
	return a.size() - n;
}

State Order::getState()
{
	State s;
	s.time[0] = time[0];
	s.time[1] = time[1];
	s.offline = offline;
	return s;
}

void Order::setState(const State& s)
{
	time[0] = s.time[0];
	time[1] = s.time[1];
	offline = s.offline;
}

int Order::time_left(int machine)
{
	return sum[machine];
}

int Order::time_passed(int machine)
{
	return time[machine];
}

int Order::offlines()
{
	int t = 0;
	for (Step x = offline; (*x) < time_passed(0)+time_left(0); ++x)
		t += x->length;
	return t;
}

void Order::init_sort()
{
	sort(left_begin(), left_end(), TaskArrivalCmp(f.tasks));
}

void Order::init_greedy()
{
	State start = getState();
	while (tasks_size() != f.tasks.size())
	{
		int best = numeric_limits<int>::max();
		VI t;
		for (VI i = left_begin(); i != left_end(); ++i)
		{
			State s = getState();
			add(i);
			if (time_passed(1) < best)
			{
				best = time_passed(1);
				t = i;
			}
			remove(i);
			setState(s);
		}
		add(t);
	}
	while (tasks_size() > 0)
		remove(tasks_end()-1);
	setState(start);
}

int Order::shortest_left(int machine)
{
	if (left_size() > 0)
		return f.tasks[*min_element(left_begin(),left_end(),TaskSumCmp(f.tasks,machine))].sums[machine];
	else
		return 0;
}

int Order::soonest_left()
{
	if (left_size() > 0)
		return f.tasks[*min_element(left_begin(),left_end(),TaskArrivalCmp(f.tasks))].arrival;
	else
		return 0;
}