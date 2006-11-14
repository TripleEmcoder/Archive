#pragma once

#include <vector>
#include <istream>
#include <ostream>
using namespace std;

#define foreach(c, i) \
    typedef __typeof__(c) c##_type; \
    for(c##_type::iterator i = c.begin(); i != c.end(); ++i)

template<class T> ostream& operator<<(ostream& os, const vector<T>& v);
template<class T> istream& operator>>(istream& is, vector<T>& v);

struct Period
{
	int start;   //moment rozpoczecia
	int length;  //dlugosc okresu

	int stop;    //moment zakonczenia
	
	Period(int start=0, int length=0);
};

bool operator<(const Period& p1, const Period& p2);
bool operator<(const Period& p, int start);

ostream& operator<<(ostream& os, const Period& p);
istream& operator>>(istream& is, Period& p);

struct Task
{
	int arrival;     //moment przybycia
	int setups[2];   //czasy rozruchu
	int lengths[2];  //czasy trwania

	int sums[2];     //sumy powyzszych
};

ostream& operator<<(ostream& os, const Task& t);
istream& operator>>(istream& is, Task& t);

struct Flowshop
{
	vector<Period> offlines;
	vector<Task> tasks;
};

ostream& operator<<(ostream& os, const Flowshop& f);
istream& operator>>(istream& is, Flowshop& f);

struct TaskSchedule
{
	vector<Period> periods[2];
};

ostream& operator<<(ostream& os, const TaskSchedule& fs);
istream& operator>>(istream& is, TaskSchedule& fs);

struct FlowshopSchedule
{
	vector<TaskSchedule> tasks;

	FlowshopSchedule(Flowshop& f);
};

ostream& operator<<(ostream& os, const FlowshopSchedule& fs);
istream& operator>>(istream& is, FlowshopSchedule& fs);
