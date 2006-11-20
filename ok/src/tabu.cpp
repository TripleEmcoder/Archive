#include "data.hpp"
#include "common.hpp"

#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <limits>
#include <ctime>

using namespace std;

unsigned max_tabu = 3;
int max_count = 5;
int max_reset = 5;
unsigned range = 5;

struct Move;

typedef vector<int> Order;
typedef set<Move> Tabulist;

struct Result
{
	int cmax;
	Order order;
	bool operator<(const Result& a)	{ return cmax < a.cmax; }
};

struct Move
{
	unsigned first, second, range;
	int a,b;
	mutable unsigned valid;
	Order* order; 
	bool next();
	void make();
	void make_inv();
	bool isnotvalid() const { return valid == 0; }
	void update() const { --valid; }
	Move invert() const { return Move(second,first,valid,range,order);	}
	Move(unsigned first, unsigned second, unsigned valid,unsigned range, Order* order): 
		first(first), second(second), valid(valid), range(range), order(order) { }
};

bool operator<(const Move& a, const Move& b) 
{ 
	return a.first < b.first || (a.first == b.first && a.second < b.second);
}

bool Move::next()
{
	if (second + 2 == first)
		second += 3;
	else
		second++;

	if (second == order->size() || second > first + range)
	{
		first++;
		if (range == 1)
			first = (second == order->size()) ? second : first;
		else if (first == 1)
			second = 2;
		else if (first+1 > range)
			second = first - range;
		else
			second = 0;
	}

	return first < order->size();
}

void Move::make()
{
	int temp = (*order)[first];
	order->erase(order->begin()+first);
	order->insert(order->begin()+second,temp);
	//swap(p[i], p[j]);
}

void Move::make_inv()
{
	invert().make();
}
	
ostream& operator<<(ostream& os, Order& p)
{
	for (size_t i=0; i<p.size(); ++i)
		os << p[i] << " ";
	return os;
}

void update_tabu(Tabulist& tabu, Move& move)
{
	if (max_tabu > 0)
	{
		for_each(tabu.begin(),tabu.end(),mem_fun_ref(&Move::update));
		Tabulist::iterator notvalid;
		while ((notvalid = find_if(tabu.begin(),tabu.end(),mem_fun_ref(&Move::isnotvalid))) != tabu.end())
			tabu.erase(notvalid);
		tabu.insert(move);
		tabu.insert(move.invert());
	}
}

Result local_min(Flowshop& f, Order& p, Tabulist& tabu, Result& best_result)
{
	Result result, result_asp;
	result.cmax = numeric_limits<int>::max();
	result_asp.cmax = numeric_limits<int>::max();
	
	Move move(0,0,max_tabu,range,&p);
	Move move_min(0,0,max_tabu,range,&p);

	while (move.next())
	{
		bool in_tabu = tabu.find(move) != tabu.end();

		move.make();
		
		int cmax = simulate(f, p);

		if (cmax < result.cmax && ( (!in_tabu) || (cmax < best_result.cmax) ))
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

		move.make_inv();
	}

	if (result.cmax < numeric_limits<int>::max())
	{
		//cerr << result.cmax << " " /*<< result.order */ << move_min.first << "->" << move_min.second << endl;
		update_tabu(tabu,move_min);
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

struct TaskArrivalCmp
{
	vector<Task>& p;
	bool operator()(const int& a, const int& b)
	{
		return p[a].arrival < p[b].arrival;
	}
	TaskArrivalCmp(vector<Task>& p): p(p) { };
};

int main(int argc, char* argv[])
{
	if (argc==5)
	{
		max_tabu = atoi(argv[1]);
		max_count = atoi(argv[2]);
		max_reset = atoi(argv[3]);
		range = atoi(argv[4]);
	}
	else
		return 1;

	srand((unsigned)time(0));
	
	Flowshop f;
	cin >> f;

	Result best_result;

	best_result.order.resize(f.tasks.size());
	for (unsigned i=0; i<best_result.order.size(); ++i)
		best_result.order[i] = i;

	//random_shuffle(best_result.order.begin(),best_result.order.end());
	sort(best_result.order.begin(),best_result.order.end(),TaskArrivalCmp(f.tasks));

	best_result.cmax = simulate(f,best_result.order);
	
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
