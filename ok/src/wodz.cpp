#include "data.hpp"
#include "common.hpp"

#include <iostream>
#include <algorithm>
#include <iterator>
using namespace std;

int main()
{
	Flowshop f;
	cin >> f;
	
	vector<int> p;
	copy(istream_iterator<int>(cin), istream_iterator<int>(), back_inserter(p));
	//cout << p;
	
	cout << f;
	cout << simulate(f, p) << endl;
	cout << schedule(f, p) << endl;
	
	return 0;
}
