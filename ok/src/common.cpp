#include "common.hpp"

int schedule(Flowshop& f, FlowshopSchedule& fs, vector<int>& p)
{
	int time[2] = {0, 0};

	for (int i=0; i<p.size(); i++)
	{
		Task& t = f.tasks[p[i]];

		time[0] = max(time[0], t.arrival);
		time[1] = max(time[0]+t.setups[0]+t.lengths[0], time[1]+t.setups[1]);
		time[0] = time[1]-t.setups[0]-t.lengths[0];

		fs.tasks[0][p[i]].periods.push_back(Period(time[0]+t.setups[0], t.lengths[0]));
		fs.tasks[1][p[i]].periods.push_back(Period(time[1], t.lengths[1]));

		time[0] += t.setups[0] + t.lengths[0];
		time[1] += t.lengths[1];

		//TODO: okresy bezczynnosci			
	}
	
	return time[1];
}
