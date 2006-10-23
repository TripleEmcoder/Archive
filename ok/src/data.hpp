#pragma once

#include <vector>
#include <istream>
#include <ostream>
using namespace std;

struct Period
{
	int start;   //moment rozpoczecia
	int length;  //dlugosc okresu
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
};

istream& operator>>(istream& is, Flowshop& f);
ostream& operator<<(ostream& os, FlowshopSchedule& s);
