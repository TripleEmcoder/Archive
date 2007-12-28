#include "stdafx.h"

#include "schedule.hpp"
#include "order.hpp"
#include "tabusearch.hpp"

using namespace std;

int call_count = 0;
int found = 0;
int app;
//int shortage[500];
boost::timer timer;

int approx0(Flowshop&, Order& p)
{
	return p.time_passed(1);
}

/*
approx1

time_passed, time_left to wiadomo

offline_sum liczy offlines od time[0] do time[0] + time_left(0), ¿eby nie policzyæ offlines które s¹ za przewidywanym koñcem
*/

int approx1(Flowshop&, Order& p)
{
	int m1_begin = p.time_passed(0);
	int m2_begin = p.time_passed(1);
	int m1 = m1_begin + p.time_left(0) + p.offlines_sum();
	int m2 = m2_begin + p.time_left(1);
	return max(m1,m2);
}

/*
approx2

approx1 +

m1_start - zwraca minimalne przesuniêcie rozpoczêcia pracy na pierwszej maszynie w stosunku do time[0]. Przesuniêcie mo¿e wynikaæ z tego, ¿e dla wszystkich zadañ arrival > time[0] lub z koniecznoœci podzielenia zadania. (trochê mo¿na poprawiæ tê funkcjê, jak starczy czasu to tak zrobimy, bo teraz te dwie sytuacje, tzn. za du¿e arrivals i podzia³ s¹ wykrywane roz³¹cznie, a mo¿na wykrywaæ obie naraz)

m2_start - zwraca minimalne przesuniêcie rozpoczêcia pracy na drugiej maszynie w stosunku do time[1]. Za najwczeœniejszy mo¿liwy pocz¹tek uznaje najmniejsz¹ z wartoœci x = max(time[0], arrival) + sums[0] liczon¹ dla wszystkich pozosta³ych zadañ. Je¿eli x > time[1] to zwraca x - time[1], wpp. 0. Nie uwzglêdnia istnienia offlines.

nowait_shift - wykrywa sytuacjê w której warunek nowait lub arrival wymusza rozpoczêcie zadania po time[0] (zamiast dok³adnie w time[0]). Nie uwzglêdnia istnienia offlines. Tu jest ciê¿ka sprawa, bo nowait_shift robi podobn¹ rzecz jak m1_start i trzeba uwa¿aæ ¿eby nie policzyæ 2 razy tego samego, wiêc mo¿e jednak nie da siê poprawiæ m1_start tak jak myœla³em. Ogólnie jest to nietrywialne i mo¿e lepiej nie tykaæ :D 

shortest_left - wybiera najkrótsze zadanie wg czêœci na drugiej maszynie. Zwrócon¹ wartoœæ mo¿na bezpiecznie dodaæ do czasu na pierwszej maszynie, bo druga musi skoñczyæ dzia³anie po pierwszej o co najmniej tyle jednostek czasu ile wynosi d³. najkrótszego zadania.
*/

int approx2(Flowshop&, Order& p)
{
	int m1_begin = p.time_passed(0) + p.m1_start() + p.nowait_shift();
	int m2_begin = p.time_passed(1) + p.m2_start();
	int m1 = m1_begin + p.time_left(0) + p.offlines_sum() + p.shortest_left(1);
	int m2 = m2_begin + p.time_left(1);
	return max(m1,m2);
}

/*
approx 3

m1start , m2_start i no-waitshift zawieraj¹ siê w machine_starts wiêc nie mo¿na ich dodawaæ drugi raz, shortest_left mo¿e zostaæ

machine_starts - wylicza wszystkie przesuniêcia zwi¹zane z ustawieniem zadania (po prostu je ustawia i odejmuje jego d³ugoœæ i ewentualnie d³ugoœæ offline'ów)
*/

int approx3(Flowshop&, Order& p)
{
	pair<int, int> starts = p.machine_starts();
	int m1 = p.time_passed(0) + starts.first + p.time_left(0) + p.offlines_sum() + p.shortest_left(1);
	int m2 = p.time_passed(1) + starts.second + p.time_left(1);
	return max(m1,m2);
}

void branch(Flowshop& f, Order& p, Result& best)
{
	call_count++;

	if (p.tasks_size() == f.tasks.size())
	{
		if (p.time_passed(1) < best.cmax)
		{
			best.cmax = p.time_passed(1);
			best.order = vector<int>(p.tasks_begin(), p.tasks_end());
			found = call_count;
		}
	}
	else
	{
		int cmax;
		switch (app)
		{
			case 0:
				cmax = approx0(f, p);
				break;
			case 1:
				cmax = approx1(f, p);
				break;
			case 2:
				cmax = approx2(f, p);
				break;
			case 3:
			default:
				cmax = approx3(f, p);
				break;
		}
	
		for (VI i = p.left_begin(); i != p.left_end(); ++i)
		{
			if (cmax < best.cmax)
			{
				//shortage[(best.cmax - cmax - 1)/5]++;
				State s = p.getState();
				p.add(i);
				branch(f,p,best);
				p.remove(i);
				p.setState(s);
			}
			else
				break;
		}
	}
}


int main(int argc, char* argv[])
{
	int init, init2;
	
	if (argc == 4)
	{
		init = atoi(argv[1]);
		app = atoi(argv[2]);
		init2 = atoi(argv[3]);
	}
	else
	{
		cerr << "Zla liczba argumentow: " << argc << endl;
		return 1;
	}

	if (init < 1 || init > 3)
	{
		cerr << "Zla wartosc init: " << init << endl;
		return 1;
	}

	if (app < 0 || app > 3)
	{
		cerr << "Zla wartosc app: " << app << endl;
		return 1;
	}
	
	if (init2 < 1 || init2 > 2)
	{
		cerr << "Zla wartosc init2: " << init2 << endl;
		return 1;
	}
	
	Flowshop f;
	cin >> f;

	Order p(f);
	
	Result best;
	
	switch (init*init2)
	{
		case 1: best = p.init_sort(); break;
		case 2: best = p.init_greedy(); break;
		case 3: best = p.init_tabu(); break;
		case 4: best = p.init2_sort(); break;
		case 5: best = p.init2_greedy(); break;
		case 6: best = p.init2_tabu(); break;
	}

	double init_time = timer.elapsed();
	
	timer.restart();
	branch(f, p, best);
	double time = timer.elapsed();

	cout << f;
	cout << best.cmax << endl;
	cout << schedule(f, best.order);

	//cerr << best.cmax << endl;
	
	cerr << call_count << "," << init_time << "," << time << "," << init_time+time << endl << endl;

	//for (int i = 0; i < 20; ++i)
	//	cerr << i*5+1 << "-" << i*5+5 << ": " << shortage[i] << endl; 
	
	return 0;
}
