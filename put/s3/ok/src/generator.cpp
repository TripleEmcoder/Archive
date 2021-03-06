#include <boost/date_time/posix_time/posix_time.hpp>

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

struct TaskSumCmp
{
	int x;
	TaskSumCmp(int x): x(x) { }
	bool operator()(const Task& a, const Task& b) { return a.sums[x] < b.sums[x]; }
};

struct TaskArrivalCmp
{
	TaskArrivalCmp() { }
	bool operator()(const Task& a, const Task& b) { return a.arrival < b.arrival; }
};

struct TaskCmp
{
	TaskCmp() { }
	bool operator()(const Task& a, const Task& b) { return a.sums[0]+a.arrival < b.sums[0] + b.arrival; }
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
	return (int)(((double)rand() / (double)RAND_MAX) * (max-min+1) + min);
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
	int a,b,c;	
	
	if (argc==4)
	{
		a = atoi(argv[1]);
		b = atoi(argv[2]);
		c = atoi(argv[3]);
	}
	else
		return 1;

	srand((unsigned)microsec_clock::local_time().time_of_day().total_microseconds()*c);


	//cin >> a >> b;
	
	vector<Period> offlines(a);
	vector<Task> tasks(b);
	
	generate(offlines.begin(),offlines.end(),OfflineGen(1,100,(int)(tasks.size()*64+offlines.size()*51),1,offlines));
	sort(offlines.begin(),offlines.end());
	
	generate(tasks.begin(),tasks.end(),TaskGen(2,100,(int)(tasks.size()*64)));

	int m1 = accumulate(tasks.begin(),tasks.end(),0,TaskSum(0));
	int m2 = accumulate(tasks.begin(),tasks.end(),0,TaskSum(1));
	int off = accumulate(offlines.begin(),offlines.end(),0,OfflineSum());

	//cerr << "Off/M1: " << 100*(double)off/(double)m1 << "%" << endl;

	m1 += off; 
	m1 += min_element(tasks.begin(),tasks.end(),TaskArrivalCmp())->arrival;
	m1 += min_element(tasks.begin(),tasks.end(),TaskSumCmp(1))->sums[1];
	vector<Task>::iterator min = min_element(tasks.begin(),tasks.end(),TaskCmp());  
	m2 += min->sums[0] + min->arrival;

	cout << offlines;
	
	cout << tasks;

	cerr << "M1: " << m1 << endl;
	cerr << "M2: " << m2 << endl;
	cerr << "Teoretyczne minimum: " << max(m1,m2) << endl;

	return 0;
}
