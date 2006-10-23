#pragma once

#include <vector>
#include <istream>
#include <ostream>
using namespace std;

#define foreach(c, i) \
    typedef __typeof__(c) c##_type; \
    for(c##_type::iterator i = c.begin(); i != c.end(); ++i)

struct Period
{
	int start;   //moment rozpoczecia
	int length;  //dlugosc okresu
	Period(int start = 0, int length = 0); 
};

struct PeriodLess
{
	bool operator()(Period& p1, Period& p2);
};

struct Machine
{
	vector<Period> offlines; //okresy bezczynnosci	
};

struct Task
{
	int arrival;     //moment przybycia
	int setups[2];   //czasy rozruchu
	int lengths[2];  //czasy trwania
};

struct Flowshop
{
	Machine machines[2];
	vector<Task> tasks;
};

struct TaskSchedule
{
	vector<Period> periods;
};

struct FlowshopSchedule
{
	vector<TaskSchedule> tasks[2];
	FlowshopSchedule(Flowshop& f);
};

istream& operator>>(istream& is, Flowshop& f);
ostream& operator<<(ostream& os, FlowshopSchedule& fs);
