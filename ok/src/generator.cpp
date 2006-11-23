#include <boost/date_time/posix_time/posix_time.hpp>

#include <ctime>
#include <algorithm>
#include <numeric>
#include <iostream>
#include <vector>
#include "data.hpp"

using namespace std;
using namespace boost::posix_time;

struct TaskGen
{
	int a,b,total;
	Task operator()();
	TaskGen(int a, int b, int total): a(a), b(b), total(total) { }
};

struct TaskSum
{
	int x;
	TaskSum(int x): x(x) { }
	int operator()(int val,Task& t)	{ return val + t.sums[x]; }
};

struct TaskCmp
{
	int x;
	TaskCmp(int x): x(x) { }
	bool operator()(const Task& a, const Task& b) { return a.sums[x] < b.sums[x]; }
};

struct OfflineSum
{
	int operator()(int val, Period& t)	{ return val + t.length; }
};

struct OfflineGen
{
	int a,b,min_dist,total;
	vector<Period>& offlines;
	bool verify(Period& x);
	Period operator()();
	OfflineGen(int a, int b, int total, int min_dist, vector<Period>& offlines) 
		:a(a), b(b), min_dist(min_dist), total(total), offlines(offlines)  { }
};

int randint(int min, int max)
{
	return (int)(((double)rand() / (double)RAND_MAX) * (max-min) + min);
}

Task TaskGen::operator()()
{
	Task t;
	t.arrival = randint(0,total/2);
	t.lengths[0] = randint(a,b);
	t.lengths[1] = randint(a,b);
	t.setups[0] = randint(1,t.lengths[0]/2);
	t.setups[1] = randint(1,t.lengths[1]/2);
	t.sums[0] = t.lengths[0] + t.setups[0];
	t.sums[1] = t.lengths[1] + t.setups[1];
	return t;
}

bool OfflineGen::verify(Period& x)
{
	for (vector<Period>::iterator i = offlines.begin(); i!= offlines.end(); ++i)
	{
		if ( (x.start-min_dist >= i->start && x.start-min_dist <= i->stop) ||
			 (x.stop+min_dist >= i->start && x.stop+min_dist <= i->stop) ||
			 (x.start-min_dist <= i->start && x.stop+min_dist >= i->stop) )
			 return false;
	}
	return true;
}

Period OfflineGen::operator()()
{
	Period t;
	do
	{
		t.start = randint(0,total);
		t.length = randint(a,b);
		t.stop = t.start + t.length;
	} while (!verify(t));
	return t;
}

int main(int argc, char* argv[])
{
	srand((unsigned)microsec_clock::local_time().time_of_day().total_microseconds());

	int a,b;	
	
	if (argc==3)
	{
		a = atoi(argv[1]);
		b = atoi(argv[2]);
	}
	else
		return 1;

	//cin >> a >> b;
	
	vector<Period> offlines(a);
	vector<Task> tasks(b);
	
	generate(offlines.begin(),offlines.end(),OfflineGen(1,100,(int)(tasks.size()*64+offlines.size()*50),1,offlines));
	sort(offlines.begin(),offlines.end());
	
	generate(tasks.begin(),tasks.end(),TaskGen(2,100,(int)(tasks.size()*64)));

	int m1 = accumulate(tasks.begin(),tasks.end(),0,TaskSum(0));
	int m2 = accumulate(tasks.begin(),tasks.end(),0,TaskSum(1));
	int off = accumulate(offlines.begin(),offlines.end(),0,OfflineSum());

	cerr << "M1: " << m1 << endl;
	cerr << "M2: " << m2 << endl;
	cerr << "Off: " << off << endl;
	cerr << "Off/M1: " << 100*(double)off/(double)m1 << "%" << endl;

	m1 += off; 
	m1 += min_element(tasks.begin(),tasks.end(),TaskCmp(1))->sums[1];
	m2 += min_element(tasks.begin(),tasks.end(),TaskCmp(0))->sums[0];

	cout << offlines;
	
	cout << tasks;

	cerr << "Teoretyczne minimum: " << max(m1,m2) << endl;

	return 0;
}
