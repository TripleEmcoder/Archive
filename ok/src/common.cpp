#include "common.hpp"

#include <algorithm>
#include <iostream>

int sum(Task& t, vector<Period>& o, int time[2])
{
	//poczatek ciagu przerw w przedziale <time[0], time[1])
	vector<Period>::iterator o1 = lower_bound(o.begin(), o.end(), time[0]);
			
	//koniec ciagu przerw w przedziale <time[0], time[1])
	vector<Period>::iterator o2 = lower_bound(o.begin(), o.end(), time[1]);
	if (o2 != o.end() && o2->start == time[1]) o2++; //upper_bound

	//suma dlugosci, przerw i odpowiedniej liczby przygotowan
	int result = t.sums[0];
	
	if (o1<o2)
		for (vector<Period>::iterator j=o1; j!=o2; j++)
		{
			result += t.setups[0] + j->length;
		}

	return result;
}

int schedule(Flowshop& f, FlowshopSchedule& fs, vector<int>& p)
{
	int time[2] = {0, 0};
	
	for (size_t i=0; i<p.size(); i++)
	{
		Task& t = f.tasks[p[i]];
		TaskSchedule& ts = fs.tasks[p[i]];
		
		//popchniecie czasu do momentu przybycia
		time[0] = max(time[0], t.arrival);

		//dopasowanie do wymagania no-wait	
		int total = sum(t, f.offlines, time);
		if (p[i] == 5)
			cerr << time[0] << " " << time[1] << " " << total << endl;
			
		time[1] = max(time[1], time[0] + total);
		time[0] = time[1] - total;
		
		int remaining = t.lengths[0];
				
		vector<Period>::iterator j = f.offlines.begin();
		
		while (j != f.offlines.end())
		{
			j = lower_bound(j, f.offlines.end(), time[0]);
			if (j != f.offlines.end() && j->start == time[0]) j++; //upper_bound

			//popychamy czas do konca poprzedniej przerwy
			if (j != f.offlines.begin())
				time[0] = max(time[0], (j-1)->stop);	

			if (j != f.offlines.end())
				//czy jest czas wykonac cokolwiek z zadania
				if (j->start - time[0] > t.setups[0])
				{
					//czesc ktora zostanie wykonana w tym okresie
					int part = min(remaining, j->start - time[0] - t.setups[0]);
					ts.periods[0].push_back(Period(time[0] + t.setups[0], part));
				
					remaining -= part;
				
					//popychamy czas na koniec okresu przetwarzania
					time[0] = time[0] + t.setups[0] + part;
				
					if (remaining == 0)
						break;
				}
				else
				{
					time[0] = j->stop;
				}
		}	

		if (remaining > 0)
		{
			//koniec przerw, wrzucamy wszystko co zostalo
			ts.periods[0].push_back(Period(time[0] + t.setups[0], remaining));
			time[0] = time[0] + t.setups[0] + remaining;
		}

		//druga maszyna rozpoczyna natychmiast po pierwszej
		time[1] = time[0];

		ts.periods[1].push_back(Period(time[1]+t.setups[1], t.lengths[1]));
		time[1] += t.setups[1] + t.lengths[1];
	}
	
	return time[1];
}

bool verify(vector<Period>& v)
{
	sort(v.begin(), v.end());

	for (size_t i=0; i<v.size()-1; i++)
	{
		/*
		cerr << v[i].start << " " << v[i].stop;
		cerr << " ";
		cerr << v[i+1].start << " " << v[i+1].stop;
		cerr << endl;
		*/
	
		if (v[i].stop > v[i+1].start)
			return false;
	}
	
	return true;
}

bool verify(Flowshop& f, FlowshopSchedule& fs)
{
	for (size_t i=0; i<f.tasks.size(); i++)
	{
		Task& t = f.tasks[i];
        TaskSchedule& ts = fs.tasks[i];

		int sum = 0;
		for (size_t j=0; j<ts.periods[0].size(); j++)
			sum += ts.periods[0][j].length;

		//czy na maszynie pierwszej wykonano dokladnie tyle pracy ile trzeba
		if (sum != t.lengths[0])
			return false;

		//na drugiej maszynie jest tylko jeden okres pracy
		if (ts.periods[1][0].length != t.lengths[1])
			return false;

		//czy jest spelniony warunek no-wait
		if (ts.periods[0].back().stop != ts.periods[1].front().start - t.setups[1])
			return false;
	}

	//sprawdzanie nachodzenia przerw, przygotowan i pracy
	vector<Period> v[2];
	v[0].insert(v[0].end(), f.offlines.begin(), f.offlines.end());

	for (size_t i=0; i<f.tasks.size(); i++)
	{
		Task& t = f.tasks[i];
        TaskSchedule& ts = fs.tasks[i];

		v[0].insert(v[0].end(), ts.periods[0].begin(), ts.periods[0].end());
		v[1].insert(v[1].end(), ts.periods[1].begin(), ts.periods[1].end());

		for (size_t j=0; j<ts.periods[0].size(); j++)
			v[0].push_back(Period(ts.periods[0][j].start-t.setups[0], t.setups[0]));
	}
	
//	if (!verify(v[0]) || !verify(v[1]))
//		return false;
		
	return true;
}
