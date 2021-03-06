#include "stdafx.h"
#include "data.hpp"
#include "schedule.hpp"
#include "move.hpp"
#include "tabulist.hpp"
#include "tabusearch.hpp"

using namespace std;

typedef MoveSwap MoveType;
typedef Tabulist TabuType;

class TaskArrivalCmp
{
	vector<Task>& p;
public:
	bool operator()(const int& a, const int& b)	{return p[a].arrival < p[b].arrival;}
	TaskArrivalCmp(vector<Task>& p): p(p) { };
};

bool operator<(const Result& a, const Result& b)
{
	return a.cmax < b.cmax;
}

Result local_min(Flowshop& f, vector<int>& p, Tabulist& tabu, int cmax_min)
{
	Result result, result_asp;
	result.cmax = numeric_limits<int>::max();
	
	MoveType* move = new MoveType;
	MoveType* move_min = new MoveType;
	
	while (move->next(p))
	{
		bool in_tabu = tabu.is_tabu(move);

		move->make(p);
		
		int cmax = simulate(f, p);

		if (cmax < result.cmax && ( (!in_tabu) || (cmax < cmax_min) ))
		{
			result.order = p;
			result.cmax = cmax;
			*move_min = *move;
		}

		move->make_inv(p);
	}

	delete move;

	tabu.update(move_min);
	return result;
}

Result initialize(Flowshop& f)
{
	Result result;
	result.order.resize(f.tasks.size());
	for (unsigned i = 0; i < result.order.size(); ++i)
		result.order[i] = i;

	sort(result.order.begin(), result.order.end(), TaskArrivalCmp(f.tasks));

	result.cmax = simulate(f, result.order);
	return result;
}
	

Result tabusearch(Flowshop& f, int tabus, int chances, int resets, int distance)
{
	Result best_result = initialize(f);

	int count = 0;
	int cmax_min = best_result.cmax;
	
	TabuType tabu(f.tasks.size(), tabus);
	Move::size = f.tasks.size();
	Move::range = distance;
	vector<int> p = best_result.order;

	while (resets > 0)
	{
		Result result = local_min(f, p, tabu, cmax_min);
		
		p = result.order;

		if (result < best_result)
			best_result = result;

		if (result.cmax < cmax_min)
		{
			cmax_min = result.cmax;
		}
		else if (++count >= chances)
		{
			cmax_min = numeric_limits<int>::max();
			count = 0;
			random_shuffle(p.begin(), p.end());
			tabu.clear();
			resets--;
		}
	}

	return best_result;
}
