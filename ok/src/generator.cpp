#include <ctime>
#include <algorithm>
#include <numeric>
#include <iostream>
#include <vector>

#include "data.hpp"

#include <sys/time.h>

using namespace std;

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
	int a,b,total,min_dist;
	vector<Period>& offlines;
	bool verify(Period& x);
	Period operator()();
	OfflineGen(int a, int b, int total, int min_dist, vector<Period>& offlines) 
		:a(a), b(b), min_dist(min_dist), total(total), offlines(offlines)  { }
};

int randint(int min, int max)
{
	return ((double)rand() / (double)RAND_MAX) * (max-min) + min;
}

Task TaskGen::operator()()
{
	Task t;
	t.arrival = randint(0,0.5*total);
	//t.arrival = 0;
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

Period OfflineGen::operator ()()
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
	timeval t1;
	gettimeofday(&t1,NULL);
	srand(t1.tv_usec);
	
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
	
	generate(offlines.begin(),offlines.end(),OfflineGen(10,30,tasks.size()*75+offlines.size()*20,30,offlines));
	sort(offlines.begin(),offlines.end());
	
	generate(tasks.begin(),tasks.end(),TaskGen(5,100,tasks.size()*75));

	int m1 = accumulate(tasks.begin(),tasks.end(),0,TaskSum(0));
	int m2 = accumulate(tasks.begin(),tasks.end(),0,TaskSum(1));

	cerr << "M1: " << m1 << endl;
	cerr << "M2: " << m2 << endl;

	m1 = accumulate(offlines.begin(),offlines.end(),m1,OfflineSum());
	m1 += min_element(tasks.begin(),tasks.end(),TaskCmp(1))->sums[1];
	m2 += min_element(tasks.begin(),tasks.end(),TaskCmp(0))->sums[0];

	cout << offlines;
	
	cout << tasks;

	cerr << "Teoretyczne minimum: " << max(m1,m2) << endl;

	return 0;
}