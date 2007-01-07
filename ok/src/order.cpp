#include "stdafx.h"
#include "order.hpp"
#include "schedule.hpp"

struct TaskArrivalCmp
{
	vector<Task>& p;
	bool operator()(const int& a, const int& b)	{return p[a].arrival < p[b].arrival;}
	TaskArrivalCmp(vector<Task>& p): p(p) { };
};

struct TaskSumsCmp
{
	vector<Task>& p;
	int x;
	bool operator()(const int& a, const int& b) { return p[a].sums[x] < p[b].sums[x];}
	TaskSumsCmp(vector<Task>& p, int x): p(p), x(x) { };
};

Order::Order(Flowshop& f) :f(f)
{
	a.resize(f.tasks.size());
	sum[0] = 0;
	sum[1] = 0;
	for (int i = 0; i < (int)a.size(); ++i)
	{
		a[i] = i;
		sum[0] += f.tasks[i].sums[0];
		sum[1] += f.tasks[i].sums[1];
	}
	time[0] = 0;
	time[1] = 0;
	offline = f.offlines.begin()+1;
	n = 0;
	line = a.begin();
}

void Order::add(VI i)
{
	simulate_task2(f.tasks[*i], time, offline);
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

int Order::offlines_sum()
{
	int t = 0;
	for (Step x = offline; x->stop < time_passed(0)+time_left(0); ++x)
		t += x->length;
	return t;
}

Result Order::init_sort()
{
	Result result;
	result.order = a;
	sort(result.order.begin(), result.order.end(), TaskArrivalCmp(f.tasks));
	result.cmax = simulate(f, result.order);
	return result;
}

Result Order::init_greedy()
{
	vector<int> b = a;
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

	Result result;
	result.order = a;
	result.cmax = time_passed(1);
	
	while (tasks_size() > 0)
		remove(tasks_end()-1);

	a = b;
	setState(start);

	return result;
}

Result Order::init_tabu()
{
	int n = (int)a.size();
	int moves = n*(n-1)/2;
	int tabus = moves * 2 / 3;
	int chances = tabus * 4;
	int range = n;
	return tabusearch(f, tabus, chances, 1, range);
}

Result Order::init2_sort()
{
	Result result = init_sort();
	a = result.order;
	return result;
}

Result Order::init2_greedy()
{
	Result result = init_greedy();
	a = result.order;
	return result;
}

Result Order::init2_tabu()
{
	Result result = init_tabu();
	a = result.order;
	return result;
}

int Order::shortest_left(int machine)
{
	if (left_size() > 0)
		return f.tasks[*min_element(left_begin(),left_end(),TaskSumsCmp(f.tasks,machine))].sums[machine];
	else
		return 0;
}

int Order::longest_left(int machine)
{
	if (left_size() > 0)
		return f.tasks[*max_element(left_begin(),left_end(),TaskSumsCmp(f.tasks,machine))].sums[machine];
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

struct TaskM1EndCmp
{
	vector<Task>& tasks;
	int t;
	TaskM1EndCmp(vector<Task>& tasks, int t): tasks(tasks), t(t) { };
	bool operator()(const int& a, const int& b) 
	{ 
		return max(t, tasks[a].arrival) + tasks[a].sums[0] < 
			   max(t, tasks[b].arrival) + tasks[b].sums[0]; 
	}
};

//int Order::m2_start()
//{
//	VI x = min_element(left_begin(), left_end(), TaskM1EndCmp(f.tasks, time_passed(0)));
//	int start = max(time_passed(0), f.tasks[*x].arrival);
//	int length = f.tasks[*x].sums[0];
//	if (start + length > time_passed(1))
//		return start + length - time_passed(1);
//	else
//		return 0;
//}

int Order::m2_start()
{
	VI x = min_element(left_begin(), left_end(), TaskM1EndCmp(f.tasks, time_passed(0)));
	int start = max(time_passed(0), f.tasks[*x].arrival);
	int length = f.tasks[*x].sums[0];
	if (start + length > time_passed(1))
		return start + length - time_passed(1);
	else
		return 0;
}

bool Order::contain_offlines(int a, int b)
{
	Step x = offline;
	while (x->start < b)
	{
		if (a <= x->start)
			return true;
		x++;
	}
	return false;
}

int Order::nowait_shift()
{
	if (contain_offlines(time_passed(0), time_passed(1)))
		return 0;
	int shift = time_passed(1) - time_passed(0);
	for (VI i = left_begin(); i != left_end(); ++i)
	{
		int start = max(time_passed(0), f.tasks[*i].arrival);
		start = max(start, time_passed(1)-f.tasks[*i].sums[0]);
		shift = min(shift, start - time_passed(0));
		if (shift == 0)
			break;
	}
	return shift;
}

int Order::m1_start()
{
	int shift = numeric_limits<int>::max();

	for (VI i = left_begin(); i != left_end(); ++i)
	{
		if (f.tasks[*i].arrival >= offline->start)
			shift = min(shift, offline->start - time_passed(0));
		else
		{
			int start = max(time_passed(0), f.tasks[*i].arrival);
			if (start + f.tasks[*i].setups[0] > offline->start)
				shift = min(shift, offline->start - time_passed(0));
			else if (start + f.tasks[*i].sums[0] > offline->start)
				shift = min(shift, f.tasks[*i].setups[0]);
			else 
				shift = 0;
		}

		if (shift == 0)
			break;
	}

	return shift;
}

pair<int, int> Order::machine_starts()
{
	int shift[2] = {numeric_limits<int>::max(), numeric_limits<int>::max()};

	int time[2];
	Step x;
	int time2[2];
	Step x2;

	for (VI i = left_begin(); i != left_end(); ++i)
	{
		time[0] = time_passed(0);
		time[1] = time_passed(1);
		x = offline;
		simulate_task2(f.tasks[*i], time, x);

		//time2[0] = time_passed(0);
		//time2[1] = time_passed(1);
		//x2 = offline;
		//simulate_task2(f.tasks[*i], time2, x2);

		//if (( (x->start) != (x2->start)) || (time[0] != time2[0]) || (time[1] != time2[1]))
		//{
		//	cerr << "zonk\n";
		//	time2[0] = time_passed(0);
		//	time2[1] = time_passed(1);
		//	x2 = offline;
		//	simulate_task2(f.tasks[*i], time2, x2);
		//}

		while (x > offline)
			time[0] -= (--x)->length;
		
		for (int j = 0; j < 2; ++j)
		{
			time[j] -= time_passed(j);
			time[j] -= f.tasks[*i].sums[j];

			shift[j] = min(shift[j], time[j]);
		}

		if (shift[0] == 0 && shift[1] == 0)
			break;
	}

	return make_pair(shift[0], shift[1]);
}