#pragma once

#include "data.hpp"
#include "schedule.hpp"
#include "move.hpp"
#include "tabulist.hpp"

#include <iostream>
#include <algorithm>
#include <limits>
#include <ctime>

using namespace std;

typedef vector<int> Order;

struct Result
{
	int cmax;
	Order order;
	bool operator<(const Result& a)	{ return cmax < a.cmax; }
};

class TaskArrivalCmp
{
	vector<Task>& p;
public:
	bool operator()(const int& a, const int& b)	{return p[a].arrival < p[b].arrival;}
	TaskArrivalCmp(vector<Task>& p): p(p) { };
};

ostream& operator<<(ostream& os, Order& p)
{
	for (size_t i=0; i<p.size(); ++i)
		os << p[i] << " ";
	return os;
}

Result local_min(Flowshop& f, Order& p, Tabulist& tabu, int cmax_min)
{
	Result result, result_asp;
	result.cmax = numeric_limits<int>::max();
	result_asp.cmax = numeric_limits<int>::max();
	
	Move move, move_min;
	
	while (move.next())
	{
		bool in_tabu = tabu.is_tabu(move);

		move.make(p);
		
		int cmax = simulate(f, p);

		if (cmax < result.cmax && ( (!in_tabu) || (cmax < cmax_min) ))
		{
			result.order = p;
			result.cmax = cmax;
			move_min = move;
		}

		if (cmax < result_asp.cmax)
		{
			result_asp.order = p;
			result_asp.cmax = cmax;
		}	

		move.make_inv(p);
	}

	if (result.cmax < numeric_limits<int>::max())
	{
		//cerr << result.cmax << " " /*<< result.order */ << move_min << endl;
		tabu.update(move_min);
		return result;
	}
	else	
	{
		//cerr << result_asp.cmax << " " /*<< result_asp.order*/  << endl;
		//cerr << "asp" << endl;
		tabu.clear();
		return result_asp;
	}
}


int main(int argc, char* argv[])
{
	unsigned max_tabu = 3;
	int max_count = 10;
	int max_reset = 1;
		
	if (argc==5)
	{
		max_tabu = atoi(argv[1]);
		max_count = atoi(argv[2]);
		max_reset = atoi(argv[3]);
		Move::range = atoi(argv[4]);
	}
	else
		return 1;

	srand((unsigned)time(0));
	
	Flowshop f;
	cin >> f;

	Move::size = f.tasks.size();

	Result best_result;
	best_result.order.resize(f.tasks.size());
	for (unsigned i=0; i<best_result.order.size(); ++i)
		best_result.order[i] = i;

	sort(best_result.order.begin(),best_result.order.end(),TaskArrivalCmp(f.tasks));

	best_result.cmax = simulate(f,best_result.order);
	
	int cmax_min = best_result.cmax;
	int count = 0;
	int reset_count = 0;
	Tabulist tabu(f.tasks.size(),max_tabu);
	Order p = best_result.order;
	
	while (reset_count < max_reset)
	{
		Result result = local_min(f,p,tabu,cmax_min);
		
		p = result.order;
		
		if (result < best_result)
			best_result = result;

		if (result.cmax < cmax_min)
		{
			cmax_min = result.cmax;
			count = 0;
		}
		else if (++count >= max_count)
		{
			count = 0;
			random_shuffle(p.begin(),p.end());
			cmax_min = numeric_limits<int>::max();
			tabu.clear();
			reset_count++;
			//cerr << "reset" << endl;
		}
	}
	
	cout << f;
	cout << best_result.cmax << endl;

	cout << schedule(f, best_result.order);
	
	cerr << endl << best_result.cmax << endl;

	return 0;
}
