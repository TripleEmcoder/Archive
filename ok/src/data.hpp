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

	int stop;    //moment zakonczenia
	
	Period(int start=0, int length=0);
};

bool operator<(const Period& p1, const Period& p2);
bool operator<(const Period& p, int start);

struct PeriodLess
{
	bool operator()(Period& p1, Period& p2);
};

struct Task
{
	int arrival;     //moment przybycia
	int setups[2];   //czasy rozruchu
	int lengths[2];  //czasy trwania

	int sums[2];     //sumy powyzszych
};

struct Flowshop
{
	vector<Period> offlines;
	vector<Task> tasks;
};

struct TaskSchedule
{
	vector<Period> periods[2];
};

struct FlowshopSchedule
{
	vector<TaskSchedule> tasks;

	FlowshopSchedule(Flowshop& f);
};

istream& operator>>(istream& is, Flowshop& f);
ostream& operator<<(ostream& os, FlowshopSchedule& fs);
