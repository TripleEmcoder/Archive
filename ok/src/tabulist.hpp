#pragma once

#include <iostream>
#include <vector>
#include <list>

#include "move.hpp"

using namespace std;

class Tabulist
{
	vector<bool> a;
	list<Move> b;
	size_t tasks, length;
	void update_tab(Move& m, bool val);
public:
	Tabulist(size_t tasks, size_t len);
	void update(Move& m);
	bool is_tabu(Move& m);
	void clear();
};