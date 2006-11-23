#include "tabulist.hpp"

Tabulist::Tabulist(size_t tasks, size_t len)
	:tasks(tasks), length(len)
{
	a.resize(tasks*tasks);
	a.assign(a.size(), false);
}

void Tabulist::update(Move *m)
{
	if (b.size() > 0 && b.size() >= length)
	{
		update_tab(b.front(), false);
		delete b.front();
		b.pop_front();
	}
	update_tab(m, true);
	b.push_back(m);
}

bool Tabulist::is_tabu(const Move *m)
{
	return (length > 0) && (a[m->first*tasks + m->second] || a[m->second*tasks + m->first]);
}

void Tabulist::update_tab(const Move *m, bool val)
{
	a[m->first*tasks + m->second] = val;
	a[m->second*tasks + m->first] = val;
}

void Tabulist::clear()
{
	for (list<Move*>::iterator i = b.begin(); i != b.end(); ++i)
	{
		update_tab(*i, false);
		delete (*i);
	}
	b.clear();	
}