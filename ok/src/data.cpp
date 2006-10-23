#include "data.hpp"

template<class T> istream& operator>>(istream& is, vector<T>& v)
{
	int n; is >> n;

	v.reserve(n);
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

istream& operator>>(istream& is, Machine& m)
{
	is >> m.offlines;

	return is;
}

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
	is >> f.machines[0];
	is >> f.machines[1];
	is >> f.tasks;

	return is;
}

ostream& operator<<(ostream& os, TaskSchedule& s)
{
    os << s.periods;

    return os;
};

ostream& operator<<(ostream& os, FlowshopSchedule& s)
{
	os << s.tasks;

	return os;
};
