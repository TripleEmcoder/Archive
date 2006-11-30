#pragma once

#include "data.hpp"

typedef vector<Period>::const_iterator Step;

int simulate(const Flowshop& f, const vector<int>& p);
void simulate_task(const Task& t, int time[2], Step& offline);

FlowshopSchedule schedule(const Flowshop& f, const vector<int>& p);
