#include "verify.hpp"

bool verify_separation(vector<Period>& v)
{
	sort(v.begin(), v.end());

	for (size_t i=0; i<v.size()-1; i++)
		if (v[i].stop > v[i+1].start)
			return false;
	
	return true;
}

void verify(const Flowshop& f, const FlowshopSchedule& fs)
{
	for (size_t i=0; i<f.tasks.size(); i++)
	{
		const Task& t = f.tasks[i];
        const TaskSchedule& ts = fs.tasks[i];

		//czy pierwsza maszyna zaczyna po przybyciu zadania
		if (t.arrival > ts.periods[0].front().start)
			throw "zignorowany czas przybycia";

		int sum = 0;
		for (size_t j=0; j<ts.periods[0].size(); j++)
			sum += ts.periods[0][j].length;

		//czy na maszynie pierwszej wykonano dokladnie tyle pracy ile trzeba
		if (sum != t.lengths[0])
			throw "bledna sumaryczna ilosc pracy";

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
		const Task& t = f.tasks[i];
        const TaskSchedule& ts = fs.tasks[i];

		v[0].insert(v[0].end(), ts.periods[0].begin(), ts.periods[0].end());
		v[1].insert(v[1].end(), ts.periods[1].begin(), ts.periods[1].end());

		for (size_t j=0; j<ts.periods[0].size(); j++)
			v[0].push_back(Period(ts.periods[0][j].start-t.setups[0], t.setups[0]));
	}
	
	if (!verify_separation(v[0]) || !verify_separation(v[1]))
		throw "nachodzenie przerw/przygotowan/pracy";
}
