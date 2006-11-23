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
	order.insert(order.begin()+second,temp);
	//swap(p[i], p[j]);
}

void Move::make_inv(vector<int>& order)
{
	Move(second,first).make(order);
}

ostream& operator<<(ostream& os, Move& m)
{
	return os << m.first << "->" << m.second;
}
