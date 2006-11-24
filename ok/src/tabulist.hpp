#pragma once

#include <iostream>
#include <vector>
#include <list>

#include "move.hpp"

using namespace std;

class Tabulist
{
protected:
	vector<bool> a;
	list<Move*> b;
	size_t tasks, length;
	virtual void update_tab(const Move* m, bool val);
public:
	Tabulist(size_t tasks, size_t len);
	virtual ~Tabulist();
	void update(Move* m);
	virtual bool is_tabu(const Move* m);
	void clear();
};

class Tabulist2: public Tabulist
{
	void update_tab(const Move* m, bool val);
public:
	Tabulist2(size_t tasks, size_t len);
	bool is_tabu(const Move* m);
};
