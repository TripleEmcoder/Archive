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

const size_t max_tabu = 10;
const int max_count = 15;
const int max_reset = 2;

int global_cmax_min;

int rand(size_t max)
{
	return (int)((double)rand() / (double)RAND_MAX * max);
}

void randomize_perm(Order& p)
{
	for (size_t i=0; i<p.size(); ++i)
		swap(p[i],p[rand(p.size())]);
}

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
		move.second++;
		if (move.second	== p.size())
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

class Move_eq
{
	Move m,m1;
public:	
	Move_eq(Move m): m(m), m1(Move(m.second,m.first)) {};
	bool operator()(const Move& a) { return a==m || a==m1; }; 
};


void local_min(Flowshop& f, Order& p, Tabulist& tabu, Order& k_min, FlowshopSchedule& fs_min, int& cmax_min, Move& move_min)
{
	Move move(0,0);
	while (next_move(p,move))
	{
		bool in_tabu = find_if(tabu.begin(),tabu.end(),Move_eq(move)) != tabu.end();

		make_move(p,move.first,move.second);
		
		FlowshopSchedule fs(f);
		int cmax = schedule(f, fs, p);

		if (cmax < global_cmax_min)
		{
			fs_min = fs;
			k_min = p;
			global_cmax_min = cmax_min = cmax;
			move_min = move;
		}
		else if (cmax < cmax_min && !in_tabu)
		{
			k_min = p;
			cmax_min = cmax;
			move_min = move;
		}

		make_move(p,move.second,move.first);
	}
}

int main()
{
	srand((unsigned)time(0));

	Flowshop f;
	cin >> f;

	Order p(f.tasks.size());
	for (unsigned i=0; i<p.size(); i++)
		p[i] = i;

	randomize_perm(p);

	FlowshopSchedule fs_min(f);
	Order k_min = p;
	global_cmax_min = schedule(f,fs_min,k_min);
	
	int cmax_min = numeric_limits<int>::max();
	int count = 0;
	int reset_count = 0;

	Tabulist tabu;

	while (reset_count < max_reset)
	{
		Order k;
		FlowshopSchedule fs(f);
		int cmax = numeric_limits<int>::max();
		Move move;
		local_min(f,p,tabu,k,fs,cmax,move);
		cerr << cmax << " " << k << move.first << "->" << move.second << endl;
		//cerr << cmax << endl;
		p = k;
		
		if (tabu.size() == max_tabu)
		{
			tabu.pop_front();
		}
		tabu.push_back(move);

		if (cmax < global_cmax_min)
		{
			fs_min = fs;
			global_cmax_min = cmax_min = cmax;
			count = 0;
		}
		else if (cmax < cmax_min)
		{
			cmax_min = cmax;
			count = 0;
		}
		else if (++count == max_count)
		{
			count = 0;
			randomize_perm(p);
			cmax_min = numeric_limits<int>::max();
			tabu.clear();
			reset_count++;
			cerr << "reset\n";
		}
	}
	
	cout << f;
	cout << global_cmax_min << endl;
	cout << fs_min;
	cerr << endl << global_cmax_min << endl;

	return 0;
}
