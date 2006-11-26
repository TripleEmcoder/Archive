#include "data.hpp"
#include "schedule.hpp"
#include "move.hpp"
#include "tabulist.hpp"

#include <iostream>
#include <fstream>
#include <algorithm>
#include <limits>
#include <ctime>
#include <string>
#include <boost/lexical_cast.hpp>

using namespace std;
using namespace boost;

typedef vector<int> Order;
typedef MoveSwap MoveType;
typedef Tabulist TabuType;

//vector<int> distances;

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

Result local_min(Flowshop& f, Order& p, Tabulist& tabu, int cmax_min)
{
	Result result, result_asp;
	result.cmax = numeric_limits<int>::max();
	//result_asp.cmax = numeric_limits<int>::max();
	
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

		//if (cmax < result_asp.cmax)
		//{
		//	result_asp.order = p;
		//	result_asp.cmax = cmax;
		//}	

		move->make_inv(p);
	}

	delete move;

	//if (result.cmax < numeric_limits<int>::max())
	//{
		cerr << result.cmax << " " << *move_min << endl;
		//distances[move_min->diff()]++;
		tabu.update(move_min);
		return result;
	//}
	//else	
	//{
		//cerr << "ASP" << endl;
		//return 1;
		//tabu.clear();
		//return result_asp;
	//}
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
	Order p = best_result.order;

	//ofstream os("krok0.txt");

	//os << f;
	//os << best_result.cmax << endl;
	//os << schedule(f, best_result.order);

	//os.close();

	//int t = 0;

	while (resets > 0)
	{
		Result result = local_min(f, p, tabu, cmax_min);
		
		p = result.order;

		//string s = string("krok")+lexical_cast<string>(++t)+".txt";

		//ofstream os(s.c_str());

		//os << f;
		//os << result.cmax << endl;
		//os << schedule(f, result.order);

		//os.close();
		
		if (result < best_result)
			best_result = result;

		if (result.cmax < cmax_min)
		{
			cmax_min = result.cmax;
			//count = 0;
		}
		else if (++count >= chances)
		{
			cmax_min = numeric_limits<int>::max();
			count = 0;
			random_shuffle(p.begin(), p.end());
			tabu.clear();
			resets--;
			//cerr << "reset" << endl;
		}
	}

	return best_result;
}


int main(int argc, char* argv[])
{
	if (argc != 5)
		return 1;

	srand((unsigned)time(0));

	Flowshop f;
	cin >> f;

	//distances.resize(f.tasks.size());

	Result result = tabusearch(f, atoi(argv[1]), atoi(argv[2]), atoi(argv[3]), atoi(argv[4]));

	cout << f;
	cout << result.cmax << endl;
	cout << schedule(f, result.order);

	//for (int i = 1; i < distances.size(); ++i)
	//{
	//	cerr << distances[i] << endl;
	//}
	//cerr << endl << endl;
	
	cerr << endl << result.cmax << endl;

	return 0;
}
