#pragma once

#include <iostream>
#include <vector>

using namespace std;

class Move
{
	friend class Tabulist;
	friend ostream& operator<<(ostream& os, Move& m);
protected:
	unsigned first, second;
public:
	Move(unsigned first =0, unsigned second =0);
	virtual bool next();
	virtual void make(vector<int>& order);
	virtual void make_inv(vector<int>& order);
	static unsigned range;
	static size_t size;
};

class MoveSwap: public Move
{
public:
	MoveSwap(unsigned first =0, unsigned second =0);
	bool next();
	void make(vector<int>& order);
	void make_inv(vector<int>& order);
};