#include "common.hpp"

int schedule(Flowshop& f, FlowshopSchedule& fs, vector<int>& p)
{
	int time[2] = {0, 0};

	for (int i=0; i<p.size(); i++)
	{
		Task& t = f.tasks[p[i]];
		TaskSchedule& ts = fs.tasks[p[i]];
		
		time[0] = max(time[0], t.arrival);
		time[1] = max(time[1], time[0]+t.setups[0]+t.lengths[0]);
		time[0] = time[1]-t.setups[0]-t.lengths[0];
		
		//vector<Period>::iterator j = lower_bound(f.offlines, 

		ts.periods[0].push_back(Period(time[0]+t.setups[0], t.lengths[0]));
		ts.periods[1].push_back(Period(time[1]+t.setups[1], t.lengths[1]));

		time[0] += t.setups[0] + t.lengths[0];
		time[1] += t.setups[1] + t.lengths[1];

		//TODO: okresy bezczynnosci			
	}
	
	return time[1];
}
