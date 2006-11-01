#include "data.hpp"

#include <algorithm>
#include <limits>

Period::Period(int start, int length)
:
	start(start),
	length(length),
	stop(start+length)
{
}

bool operator<(const Period& p1, const Period& p2)
{
	return p1.start < p2.start;
}

bool operator<(const Period& p, int start)
{
	return p.start < start;
}

FlowshopSchedule::FlowshopSchedule(Flowshop& f)
{
    tasks.resize(f.tasks.size());
}

template<class T> istream& operator>>(istream& is, vector<T>& v)
{
	int n; is >> n;

	v.resize(n);
	for (int i=0; i<n; i++)
		is >> v[i];

	return is;
}

template<class T> ostream& operator<<(ostream& os, vector<T>& v)
{
	os << v.size() << endl;

    for (int i=0; i<(int)v.size(); i++)
        os << v[i] << " ";

	os << endl;

    return os;
}

istream& operator>>(istream& is, Period& p)
{
	is >> p.start;
	is >> p.length;
	p.stop = p.start + p.length;

	return is;
}

ostream& operator<<(ostream& os, Period& p)
{
    os << p.start;
	os << " ";
	os << p.length;

    return os;
}

istream& operator>>(istream& is, Task& t)
{
	is >> t.arrival;
	is >> t.setups[0];
	is >> t.lengths[0];
	is >> t.setups[1];
	is >> t.lengths[1];
	
	t.sums[0] = t.setups[0] + t.lengths[0];
	t.sums[1] = t.setups[1] + t.lengths[1];

	return is;
}

istream& operator>>(istream& is, Flowshop& f)
{
	is >> f.offlines;
	is >> f.tasks;

	//dla spojnosci kodu dodajemy pseudo-przerwy na krancach czasu
	f.offlines.push_back(Period(0, 0));
	f.offlines.push_back(Period(numeric_limits<int>().max(), 0));
	
	//nie ma sensu przegladac przerw inaczej niz chronologicznie
	sort(f.offlines.begin(), f.offlines.end());
	
	return is;
}

ostream& operator<<(ostream& os, Flowshop& f)
{
	vector<Period> t;
	t.insert(t.begin(),f.offlines.begin()+1,f.offlines.end()-1);
	os << t;
	os << f.tasks;

	return os;
}


ostream& operator<<(ostream& os, TaskSchedule& ts)
{
    os << ts.periods[0];
	os << ts.periods[1];

    return os;
}

ostream& operator<<(ostream& os, FlowshopSchedule& fs)
{
	os << fs.tasks;

	return os;
}

ostream& operator<<(ostream& os, Task& t)
{
	os << t.arrival << " " << t.setups[0] << " " << t.lengths[0] << " " << t.setups[1] << " " << t.lengths[1] << endl;

	return os;
}
