#pragma once

#include "data.hpp"

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
public:
	Order(Flowshop& f);

	void init_sort();
	void init_greedy();

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
	int offlines();
};