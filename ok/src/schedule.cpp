#include "stdafx.h"

#include "schedule.hpp"

#include <iostream>
#include <cassert>

void simulate_forward(int setup, int length, int& time, Step& offline)
{
	//cerr << "-> time: " << time << endl;
	
	while (offline->stop > time)
		--offline;
		
	while ((offline+1)->start < time)
		++offline;
	
	//cerr << "-> offline: " << *offline << endl; 		
	//cerr << "-> offline+1: " << *(offline+1) << endl; 
	
	assert(offline->start <= time);
	assert((offline+1)->start >= time);
		
	for (; length != 0; ++offline)
	{
		int start = max(offline->stop, time) + setup;
		int space = max((offline+1)->start - start, 0);
		int part = min(space, length);

		length -= part;
		time = start + part;
		
		if (time > (offline+1)->start)
			time = (offline+1)->stop;
		
		//cerr << "-> work: " << time << " " << start << " " << part << endl;
	}
}

void simulate_backward(int setup, int length, int& time, Step& offline)
{	
	//cerr << "<- time: " << time << endl;		
	
	while (offline->start < time)
		++offline;
		
	while ((offline-1)->stop > time)
		--offline;

	//cerr << "<- offline: " << *offline << endl;
	//cerr << "<- offline-1: " << *(offline-1) << endl;

	assert(offline->start >= time);
	assert((offline-1)->stop <= time);

	for (; length != 0; --offline)
	{
		int stop = min(offline->start, time) - setup;
		int space = max(stop - (offline-1)->stop, 0);
		int part = min(space, length);

		length -= part;
		time = stop - part;
		
		if (time < (offline-1)->stop)
			time = (offline-1)->start;
		
		//cerr << "<- work: " << time << " " << stop << " " << part << endl;
	}
}

//log(onlines.size())+length
vector<Period> schedule_periods(int setup, int length, int& time, Step& offline)
{
	vector<Period> periods;

	while (offline->stop > time)
		--offline;
		
	while ((offline+1)->start < time)
		++offline;
	
	assert(offline->start <= time);
	assert((offline+1)->start >= time);
	
	for (; length != 0; ++offline)
	{
		int start = max(offline->stop, time) + setup;
		int space = max((offline+1)->start - start, 0);
		int part = min(space, length);

		length -= part;
		time = start + part;
		
		if (time > (offline+1)->start)
			time = (offline+1)->stop;
		
		if (part > 0)
			periods.push_back(Period(start, part));
	}	

	return periods;
}

void simulate_common(const Task& t, int time[2], Step& offline)
{
	//popychamy czas do momentu przybycia zadania
	time[0] = max(time[0], t.arrival);

	//wyliczamy najkrotsze mozliwe uszeregowanie
	simulate_forward(t.setups[0], t.lengths[0], time[0], offline);

	//druga maszyna rozpoczyna po pierwszej (jesli moze)
	time[1] = max(time[0], time[1]);

	while (true)
	{
		//"nadgonienie" time[1] w wektorze offline'ów
		if (offline->start >= time[1])
		
		//znalezienie pierwszego miejsca dla 1 jednostki pracy
		if (offline->start - (offline-1)->stop >= t.setups[0]+1)
			break;
			
		++offline;
	}

	time[1] = max(time[1], (offline-1)->stop+t.setups[0]+1);
	
	time[0] = time[1];

	//dosuwamy przetwarzanie na pierwszej do poczatku drugiej
	simulate_backward(t.setups[0], t.lengths[0], time[0], offline);
}

void simulate_task(const Task& t, int time[2], Step& offline)
{
	simulate_common(t, time, offline);
	
	simulate_forward(t.setups[0], t.lengths[0], time[0], offline);
	
	time[0] = time[1];
	time[1] += t.sums[1];
	
	//cerr << "SIM: " << time[0] << " " << time[1] << " " << *offline << endl;
}

void schedule_task(const Task& t, TaskSchedule& ts, int time[2], Step& offline)
{
	simulate_common(t, time, offline);

	//generujemy uszeregowanie wg obliczonego czasu
	ts.periods[0] = schedule_periods(t.setups[0], t.lengths[0], time[0], offline);

	//dodajemy calosc zadania na maszynie drugiej
	ts.periods[1].push_back(Period(time[1]+t.setups[1], t.lengths[1]));
	
	time[0] = time[1];
	time[1] += t.sums[1];
	
	//cerr << "SIM: " << time[0] << " " << time[1] << " " << *offline << endl;
}

int simulate(const Flowshop& f, const vector<int>& p)
{
	int time[2] = {0, 0};
	vector<Period>::const_iterator offline = f.offlines.begin();
	
	for (size_t i=0; i<p.size(); i++)
	{
		//cerr << "--- SIM: " << p[i]+1 << " --- ";
		//cerr << time[0] << " " << time[1] << " " << *offline << endl;
		
		simulate_task(f.tasks[p[i]], time, offline);
	}
	
	return time[1];
}

FlowshopSchedule schedule(const Flowshop& f, const vector<int>& p)
{
	FlowshopSchedule fs(f);
	
	int time[2] = {0, 0};
	vector<Period>::const_iterator offline = f.offlines.begin();
	
	for (size_t i=0; i<p.size(); i++)
	{
		//cerr << "--- SCH: " << p[i]+1 << " --- ";
		//cerr << time[0] << " " << time[1] << " " << *offline << endl;
		
		schedule_task(f.tasks[p[i]], fs.tasks[p[i]], time, offline);
	}
	
	return fs;
}
