#include "stdafx.h"

#include "move.hpp"

unsigned Move::range;
unsigned Move::size;

Move::Move(unsigned first, unsigned second)
	:first(first), second(second) 
{

}

Move::~Move()
{
}
	
bool Move::next(vector<int>&)
{
	if (second + 2 == first)
		second += 3;
	else
		second++;

	if (second == size || second > first + range)
	{
		first++;
		if (range == 1)
			first = (second == size) ? second : first;
		else if (first == 1)
			second = 2;
		else if (first+1 > range)
			second = first - range;
		else
			second = 0;
	}

	return first < size;
}

void Move::make(vector<int>& order)
{
	int temp = order[first];
	order.erase(order.begin()+first);
	order.insert(order.begin()+second, temp);
}

void Move::make_inv(vector<int>& order)
{
	int temp = order[second];
	order.erase(order.begin()+second);
	order.insert(order.begin()+first, temp);
}

int Move::diff()
{
	return (first>second)? first-second : second-first;
}

ostream& operator<<(ostream& os, Move& m)
{
	return os << m.first << "->" << m.second;
}

MoveSwap::MoveSwap(unsigned first, unsigned second)
	:Move(first, second)
{
}

bool MoveSwap::next(vector<int>&)
{
	second++;

	if (second > first + range || second >= size)
	{
		first++;
		second = first+1;
	}

	return first+1 < size;
}

void MoveSwap::make(vector<int>& order)
{
	swap(order[first], order[second]);
}

void MoveSwap::make_inv(vector<int>& order)
{
	swap(order[second], order[first]);
}

MoveTask::MoveTask(unsigned first, unsigned second)
	:Move(0, 0), a(first), b(second)
{
}

bool MoveTask::next(vector<int>& order)
{
	b++;

	if (b > a + range || b >= size)
	{
		a++;
		b = a+1;
	}

	if (a < size && b < size)
	{
		first = order[a];
		second = order[b];
	}

	return a+1 < size;
}

void MoveTask::make(vector<int>& order)
{
	swap(order[a], order[b]);
}

void MoveTask::make_inv(vector<int>& order)
{
	swap(order[b], order[a]);
}

int MoveTask::diff()
{
	return (a>b)? a-b : b-a;
}


ostream& operator<<(ostream& os, MoveTask& m)
{
	return os << m.a << "->" << m.b;
}
