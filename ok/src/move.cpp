#include "move.hpp"

unsigned Move::range;
unsigned Move::size;

Move::Move(unsigned first, unsigned second)
	:first(first), second(second) 
{

}
	
bool Move::next()
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

ostream& operator<<(ostream& os, Move& m)
{
	return os << m.first << "->" << m.second;
}

MoveSwap::MoveSwap(unsigned first, unsigned second)
	:Move(first, second)
{
}

bool MoveSwap::next()
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

