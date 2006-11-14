#include <cstdlib>
#include <cstdio>
#include <ctime>
#include <algorithm>
#include <numeric>
#include <iostream>
#include <math.h>
#include <vector>

#include "data.hpp"

using namespace std;

struct Task_gen
{
	int a,b;
	Task operator()();
	Task_gen(int a, int b): a(a), b(b) { }
};

struct Task_sum
{
	int x;
	Task_sum(int x): x(x) { }
	int operator()(int val,Task& t)	{ return val + t.sums[x]; }
};

struct Task_cmp
{
	int x;
	Task_cmp(int x): x(x) { }
	bool operator()(const Task& a, const Task& b) { return a.sums[x] < b.sums[x]; }
};

struct Offline_sum
{
	int operator()(int val, Period& t)	{ return val + t.length; }
};

struct Offline_gen
{
	int a,b,total,min_dist;
	vector<Period>& offlines;
	bool verify(Period& x);
	Period operator()();
	Offline_gen(int a, int b, int total, int min_dist, vector<Period>& offlines) 
		:a(a), b(b), min_dist(min_dist), total(total), offlines(offlines)  { }
};

int randint(int min, int max)
{
	return ((double)rand() / (double)RAND_MAX) * (max-min) + min;
}

Task Task_gen::operator()()
{
	Task t;
	t.arrival = 0;
	t.lengths[0] = randint(a,b);
	t.lengths[1] = randint(a,b);
	t.setups[0] = randint(1,t.lengths[0]/2);
	t.setups[1] = randint(1,t.lengths[1]/2);
	t.sums[0] = t.lengths[0] + t.setups[0];
	t.sums[1] = t.lengths[1] + t.setups[1];
	return t;
}

bool Offline_gen::verify(Period& x)
{
	for (vector<Period>::iterator i = offlines.begin(); i!= offlines.end(); ++i)
	{
		if ( (x.start-min_dist > i->start && x.start-min_dist < i->stop) ||
			 (x.stop+min_dist > i->start && x.stop+min_dist < i->stop) ||
			 (x.start-min_dist < i->start && x.stop+min_dist > i->stop) )
			 return false;
	}
	return true;
}

Period Offline_gen::operator ()()
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
	srand((unsigned)time(0));
	
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
	
	generate(tasks.begin(),tasks.end(),Task_gen(5,100));

	int m1 = accumulate(tasks.begin(),tasks.end(),0,Task_sum(0));
	int m2 = accumulate(tasks.begin(),tasks.end(),0,Task_sum(1));

	generate(offlines.begin(),offlines.end(),Offline_gen(10,30,m1*1.1,40,offlines));
	sort(offlines.begin(),offlines.end());

	m1 = accumulate(offlines.begin(),offlines.end(),m1,Offline_sum());
	m1 += min_element(tasks.begin(),tasks.end(),Task_cmp(1))->sums[1];
	m2 += min_element(tasks.begin(),tasks.end(),Task_cmp(0))->sums[0];

	cout << offlines;
	
	cout << tasks;

	cerr << "Teoretyczne minimum: " << max(m1,m2) << endl;

	return 0;
}














	//int x = 0;

	//int best1 = 0;
	//int best2 = 0;

	//srand((unsigned)time(0));
	//printf("%d\n",offlines); 
	//for (int i=0; i<offlines; ++i)
	//{
	//	int start = randint(x,x+(tasks*75-x)/(offlines-i));
	//	int length = randint(1,50);
	//	best1 += length;
	//	x = start + length;
	//	printf("%.0f %.0f\n",start,length);
	//}
	//printf("%d\n",tasks); 
	//int min1 = 200;
	//int min2 = 200;
	//for (int i=0; i<tasks; ++i)
	//{
	//	//int arr = randint(0,tasks*75/5);
	//	int arr = 0;
	//	int p1 = randint(5,100);
	//	int p2 = randint(5,100);
	//	int s1 = randint(1,0.5*p1);
	//	int s2 = randint(1,0.5*p2);
	//	best1 += p1 + s1;
	//	best2 += p2 + s2;
	//	min1 = min(min1,p1+s1);
	//	min2 = min(min2,p2+s2);
	//	printf("%.0f %.0f %.0f %.0f %.0f\n",arr,s1,p1,s2,p2);
	//}
	//cerr << max(best1+min2,best2+min1);