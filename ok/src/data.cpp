#include "data.hpp"

Period::Period(int start, int length)
:
	start(start),
	length(length)
{
}

bool Period::operator<(const Period& p) const
{
	return start < p.start;
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

    for (int i=0; i<v.size(); i++)
        os << v[i] << " ";

	os << endl;

    return os;
}

istream& operator>>(istream& is, Period& p)
{
	is >> p.start;
	is >> p.length;

	return is;
}

ostream& operator<<(ostream& os, Period& p)
{
    os << p.start;
	os << " ";
	os << p.length;

    return os;
};

istream& operator>>(istream& is, Task& t)
{
	is >> t.arrival;
	is >> t.setups[0];
	is >> t.lengths[0];
	is >> t.setups[1];
	is >> t.lengths[1];

	return is;
}

istream& operator>>(istream& is, Flowshop& f)
{
	is >> f.offlines;
	is >> f.tasks;
	
	sort(f.offlines.begin(), f.offlines.end());

	return is;
}

ostream& operator<<(ostream& os, TaskSchedule& ts)
{
    os << ts.periods[0];
	os << ts.periods[1];

    return os;
};

ostream& operator<<(ostream& os, FlowshopSchedule& fs)
{
	os << fs.tasks;

	return os;
};
