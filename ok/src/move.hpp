#pragma once

#include <iostream>
#include <vector>

using namespace std;

class Move
{
	unsigned first, second;
public:
	Move(unsigned first =0, unsigned second =0);
	bool next();
	void make(vector<int>& order);
	void make_inv(vector<int>& order);
	friend class Tabulist;
	friend ostream& operator<<(ostream& os, Move& m);
	static unsigned range;
	static size_t size;
};