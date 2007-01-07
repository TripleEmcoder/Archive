#pragma once

#include "data.hpp"
#include "tabusearch.hpp"

using namespace std;

typedef vector<int>::iterator VI;

struct State
{
	int time[2];
	vector<Period>::const_iterator offline;
};

class Order
{
	Flowshop& f;
	vector<int> a;
	size_t n;
	VI line;
	int time[2];
	int sum[2];
	vector<Period>::const_iterator offline;
	bool contain_offlines(int a, int b);
public:
	Order(Flowshop& f);

	Result init_sort();
	Result init_greedy();
	Result init_tabu();

	Result init2_sort();
	Result init2_greedy();
	Result init2_tabu();
	
	State getState();
	void setState(const State& s);

	void add(VI i);
	void remove(VI i);

	VI tasks_begin();
	VI tasks_end();
	size_t tasks_size();
	VI left_begin();
	VI left_end();
	size_t left_size();

	int time_left(int machine);
	int time_passed(int machine);
	int offlines_sum();
	int shortest_left(int machine);
	int longest_left(int machine);
	int soonest_left();
	int m1_start();
	int m2_start();
	pair<int, int> machine_starts();
	int nowait_shift();
};
