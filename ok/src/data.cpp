#include "stdafx.h"

#include "data.hpp"

#include <algorithm>
#include <limits>

template<class T> ostream& operator<<(ostream& os, const vector<T>& v)
{
	os << v.size() << endl;

    for (int i=0; i<(int)v.size(); i++)
        os << v[i] << " ";
	
	os << endl;

    return os;
}

template<class T> istream& operator>>(istream& is, vector<T>& v)
{
	int n; is >> n;

	v.resize(n);
	for (int i=0; i<n; i++)
		is >> v[i];

	return is;
}

template ostream& operator<<(ostream& os, const vector<int>& v);
template istream& operator>>(istream& is, vector<int>& v);

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

ostream& operator<<(ostream& os, const Period& p)
{
    os << p.start;
	os << " ";
	os << p.length;

    return os;
}

istream& operator>>(istream& is, Period& p)
{
	is >> p.start;
	is >> p.length;
	p.stop = p.start + p.length;

	return is;
}

ostream& operator<<(ostream& os, const Task& t)
{
	os << t.arrival << " ";
	os << t.setups[0] << " ";
	os << t.lengths[0] << " ";
	os << t.setups[1] << " ";
	os << t.lengths[1] << endl;

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

ostream& operator<<(ostream& os, const Flowshop& f)
{
	vector<Period> t;
	t.insert(t.begin(), f.offlines.begin()+1, f.offlines.end()-1);
	os << t;
	os << f.tasks;

	return os;
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

ostream& operator<<(ostream& os, const TaskSchedule& ts)
{
    os << ts.periods[0];
	os << ts.periods[1];

    return os;
}

FlowshopSchedule::FlowshopSchedule(const Flowshop& f)
{
    tasks.resize(f.tasks.size());
}

ostream& operator<<(ostream& os, const FlowshopSchedule& fs)
{
	os << fs.tasks;

	return os;
}
