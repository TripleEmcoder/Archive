#include "data.hpp"
#include "common.hpp"

#include <iostream>
#include <algorithm>
#include <vector>
#include <list>
#include <limits>
#include <ctime>

using namespace std;

typedef pair<unsigned,unsigned> Move;
typedef vector<int> Order;
typedef list<Move> Tabulist;

class Result
{
public:
	int cmax;
	Order order;
	FlowshopSchedule fs;
	Result(FlowshopSchedule fs): fs(fs) { }
	bool operator<(const Result& a)	{ return cmax < a.cmax; }
};

class Move_eq
{
	Move m,m1;
public:	
	Move_eq(Move m): m(m), m1(Move(m.second,m.first)) {};
	bool operator()(const Move& a) { return a==m || a==m1; }; 
};

const size_t max_tabu = 3;
const int max_count = 10;
const int max_reset = 5;

ostream& operator<<(ostream& os, Order& p)
{
	for (size_t i=0; i<p.size(); ++i)
		os << p[i] << " ";
	return os;
}

bool next_move(Order& p, Move& move)
{
	do
	{
		if (++move.second == p.size())
		{
			move.second = 0;
			move.first++;
		}
	} while (move.first<p.size() && move.second <= move.first && move.first <= move.second+1);
	return move.first<p.size();
}

void make_move(Order& p,unsigned i, unsigned j)
{
	int temp = p[i];
	p.erase(p.begin()+i);
	p.insert(p.begin()+j,temp);
}

void update_tabu(Tabulist& tabu, Move& move)
{
	if (tabu.size() == max_tabu)
		tabu.pop_front();
	tabu.push_back(move);
}

Result local_min(Flowshop& f, Order& p, Tabulist& tabu, Result& best_result)
{
	Result result(f);
	result.cmax = numeric_limits<int>::max();
	Move move(0,0), move_min(0,0);
	
	while (next_move(p,move))
	{
		bool in_tabu = find_if(tabu.begin(),tabu.end(),Move_eq(move)) != tabu.end();

		make_move(p,move.first,move.second);
		
		FlowshopSchedule fs(f);
		int cmax = schedule(f, fs, p);

		if (cmax < best_result.cmax || (cmax < result.cmax && !in_tabu))
		{
			result.order = p;
			result.cmax = cmax;
			result.fs = fs;
			move_min = move;
		}
		
		make_move(p,move.second,move.first);
	}

	update_tabu(tabu,move_min);
	
//	cerr << result.cmax << " " << result.order << move_min.first << "->" << move_min.second << endl;

	return result;
}

int main()
{
	srand((unsigned)time(0));

	Flowshop f;
	cin >> f;

	Result best_result(f);

	best_result.order.resize(f.tasks.size());
	for (unsigned i=0; i<best_result.order.size(); i++)
		best_result.order[i] = i;

	random_shuffle(best_result.order.begin(),best_result.order.end());

	best_result.cmax = schedule(f,best_result.fs,best_result.order);
	
	int cmax_min = numeric_limits<int>::max();
	int count = 0;
	int reset_count = 0;
	Tabulist tabu;
	Order p = best_result.order;
	
	while (reset_count < max_reset)
	{
		Result result = local_min(f,p,tabu,best_result);
		
		p = result.order;
		
		if (result < best_result)
			best_result = result;

		if (result.cmax < cmax_min)
		{
			cmax_min = result.cmax;
			count = 0;
		}
		else if (++count == max_count)
		{
			count = 0;
			random_shuffle(p.begin(),p.end());
			cmax_min = numeric_limits<int>::max();
			tabu.clear();
			reset_count++;
			//cerr << "reset\n";
		}
	}
	
	cout << f;
	cout << best_result.cmax << endl;
	cout << best_result.fs;
	
	cerr << endl << best_result.cmax << endl;

	return 0;
}
