#include "common.hpp"

#include <iostream>
#include <algorithm>

int schedule(Flowshop& f, FlowshopSchedule& fs, vector<int>& p)
{
	int time[2] = {0, 0};

	for (unsigned i=0; i<p.size(); i++)
	{
		Task& t = f.tasks[p[i]];
		TaskSchedule& ts = fs.tasks[p[i]];
		
		time[0] = max(time[0], t.arrival);
		time[1] = max(time[1], time[0] + t.sums[0]);
		time[0] = time[1] - t.sums[0];

		int remaining = t.lengths[0];
		vector<Period>::iterator j = f.offlines.begin();
		
		while (true)
		{
			j = lower_bound(j, f.offlines.end(), time[0]);
		
			if (j == f.offlines.end())
				break;
				
			//cout << time[0] << " " << remaining << " " << j->start << endl;
				
			//np. zadanie przybylo w momencie rozpoczecia przerwy
			if (j->start == time[0])
				j++;

			//popychamy czas do konca poprzedniej przerwy
			time[0] = max(time[0], (j-1)->stop);
			
			if (j == f.offlines.end())
					break;		
			
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

			//bez zmian przy part>0, popchniecie przy part<0
			time[0] = j->start;
		}	

		//koniec przerw, wrzucamy wszystko co zostalo
		if (remaining > 0)
		{
			ts.periods[0].push_back(Period(time[0] + t.setups[0], remaining));
			time[0] = time[0] + t.setups[0] + remaining;
		}

		//tutaj nie jestem pewien czy moge tak sobie przepisac
		time[1] = time[0];
		
		ts.periods[1].push_back(Period(time[1]+t.setups[1], t.lengths[1]));
		time[1] += t.setups[1] + t.lengths[1];

		//TODO: okresy bezczynnosci			
	}
	
	return time[1];
}
