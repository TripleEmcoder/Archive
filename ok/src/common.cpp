#include "common.hpp"

#include <algorithm>
#include <iostream>
#include <cassert>
#include <string>

vector<Period> offlines2onlines(vector<Period>& offlines, int setup)
{
	vector<Period> onlines;
	vector<Period>::iterator i;

	for (i = offlines.begin(); i != offlines.end()-1; i++)
	{
		int start = i->stop + setup;
		int length = (i+1)->start - start;

		if (length > 0)
		{
			//cerr << "online(" << start << ", " << length << ")" << endl;
			onlines.push_back(Period(start, length));
		}
	}

	return onlines;
}

int simulate_forward(vector<Period>& onlines, int time, int length)
{
	vector<Period>::iterator i;
	
	//znajdujemy pierwszy mozliwy okres przetwarzania
	i = upper_bound(onlines.begin(), onlines.end(), time);
	
	if (i != onlines.begin() && (i-1)->stop > time)
		i--;
		
	//cerr << "time: " << time <<endl;
	//cerr << "ub: " << i->start << " " << i->length << endl;
	
	for (; length != 0; i++)
	{
		int start = max(i->start, time);
		//cerr << "length: " << length << endl;
		int part = min(i->stop - start, length);
		//cerr << "part: " << part << endl;
		length -= part;
		time = start + part;
		//cerr << "new_time: " << time << endl;
	}

	return time;
}

int simulate_backward(vector<Period>& onlines, int time, int length)
{
	vector<Period>::iterator i;
	
	//znajdujemy ostatni mozliwy okres przetwarzania
	i = upper_bound(onlines.begin(), onlines.end(), time)-1;
	//cerr << "lb: " << i->start << " " << i->length << endl;
	
	for (;; i--)
	{
		int stop = min(i->stop, time);
		//cerr << "length: " << length << endl;
		int part = min(stop - i->start, length);
		//cerr << "part: " << part << endl;
		length -= part;
		time = stop - part;
		//cerr << "new_time: " << time << endl;

        if (length == 0)
            break;
	}
	
	return time;
}

vector<Period> schedule_periods(vector<Period>& onlines, int time, int length)
{
	vector<Period> periods;
	vector<Period>::iterator i;
	
	//znajdujemy pierwszy mozliwy okres przetwarzania
	i = upper_bound(onlines.begin(), onlines.end(), time);

	if (i != onlines.begin() && (i-1)->stop > time)
		i--;

	//cerr << "time: " << time <<endl;
	//cerr << "ub: " << i->start << " " << i->length << endl;
	
	for (; length != 0; i++)
	{
		int start = max(i->start, time);
		//cerr << "length: " << length << endl;
		int part = min(i->stop - start, length);
		//cerr << "part: " << part << endl;
		length -= part;
		time = start + part;
		//cerr << "new_time: " << time << endl;
		//cerr << "work(" << start << ", " << length << ")" << endl;		
		periods.push_back(Period(start, part));
	}

	return periods;
}


void schedule_task(Flowshop& f, Task& t, TaskSchedule& ts, int time[2])
{
	//popychamy czas do momentu przybycia zadania
	time[0] = max(time[0], t.arrival);
	
	time[0] += t.setups[0];
	
	//tworzymy liste potencjalnych okresow przetwarzania
	vector<Period> onlines = offlines2onlines(f.offlines, t.setups[0]);
	
	//wyliczamy najkrotsze mozliwe uszeregowanie
	time[0] = simulate_forward(onlines, time[0], t.lengths[0]);
	//cerr << "time[0]F = " << time[0] << endl;

	//druga maszyna rozpoczyna po pierwszej (jesli moze)
	time[1] = max(time[0], time[1]);
	//cerr << "time[1]M = " << time[1] << endl;

	//kwestia no-wait a trafiania time[1] w przerwe

	vector<Period>::iterator i =
		upper_bound(f.offlines.begin(), f.offlines.end(), time[1]);

	if ((i-1)->start < time[1] && time[1] <= (i-1)->stop + t.setups[0] + 1)
		time[1] = max((i-1)->stop + t.setups[0] + 1, time[1]);	

/*
    if (i != onlines.begin() && (i-1)->stop > time[1])
        i--;

	//przetwarzanie musi trwac przynajmniej jednostke czasu
	time[1] = max(i->start + t.setups[0], time[1]);	
*/
	
	//dosuwamy przetwarzanie na pierwszej do poczatku drugiej
	time[0] = simulate_backward(onlines, time[1], t.lengths[0]);
	//cerr << "time[0]B = " << time[0] << endl;
	
	//generujemy uszeregowanie wg obliczonego czasu
	ts.periods[0] = schedule_periods(onlines, time[0], t.lengths[0]);
	
	//dodajemy calosc zadania na maszynie drugiej
	ts.periods[1].push_back(Period(time[1]+t.setups[1], t.lengths[1]));
	
	time[0] = time[1];
	time[1] += t.sums[1];

	//cerr << "time[0] = " << time[0] << endl;
	//cerr << "time[1] = " << time[1] << endl;
	
	
	/*			
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
				
				
				if (part > 0)
				{
					remaining -= part;
					
					//popychamy czas na koniec okresu przetwarzania
					time[0] = time[0] + t.setups[0] + part;
					continue;
				}
			}
		
		//ominiecie niewykorzystanego okresu
		time[0] = j->stop;
	}	

	if (remaining > 0)
	{
		//koniec przerw, wrzucamy wszystko co zostalo
		ts.periods[0].push_back(Period(time[0] + t.setups[0], remaining));
		time[0] = time[0] + t.setups[0] + remaining;
	}
	
	
	if (delay > 0)
	{
	}
	*/	
}

int schedule(Flowshop& f, FlowshopSchedule& fs, vector<int>& p)
{
	int time[2] = {0, 0};
	
	for (size_t i=0; i<p.size(); i++)
	{
		assert(p[i] >= 0);
		assert(p[i] < f.tasks.size());
		assert(p[i] < fs.tasks.size());
		
		schedule_task(f, f.tasks[p[i]], fs.tasks[p[i]], time);
	}
	
	return time[1];
}

bool verify_separation(vector<Period>& v)
{
	sort(v.begin(), v.end());

	for (size_t i=0; i<v.size()-1; i++)
	{
/*
		//cerr << v[i].start << " " << v[i].stop;
		//cerr << " ";
		//cerr << v[i+1].start << " " << v[i+1].stop;
		//cerr << endl;
*/		

		if (v[i].stop > v[i+1].start)
			return false;
	}
	
	return true;
}

void verify(Flowshop& f, FlowshopSchedule& fs)
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
			throw "bleda sumaryczna ilosc pracy";

		//na drugiej maszynie jest tylko jeden okres pracy
		if (ts.periods[1][0].length != t.lengths[1])
			throw "wiele okresow pracy";

		//czy jest spelniony warunek no-wait
		if (ts.periods[0].back().stop != ts.periods[1].front().start - t.setups[1])
			throw "niespelniony warunek no-wait";
	}

	//sprawdzanie nachodzenia przerw, przygotowan i pracy
	vector<Period> v[2];
	v[0].insert(v[0].end(), f.offlines.begin()+1, f.offlines.end());

	for (size_t i=0; i<f.tasks.size(); i++)
	{
		Task& t = f.tasks[i];
        TaskSchedule& ts = fs.tasks[i];

		v[0].insert(v[0].end(), ts.periods[0].begin(), ts.periods[0].end());
		v[1].insert(v[1].end(), ts.periods[1].begin(), ts.periods[1].end());

		for (size_t j=0; j<ts.periods[0].size(); j++)
			v[0].push_back(Period(ts.periods[0][j].start-t.setups[0], t.setups[0]));
	}
	
	if (!verify_separation(v[0]) || !verify_separation(v[1]))
		throw "nachodzenie przerw/przygotowan/pracy";
}
