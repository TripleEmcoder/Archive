#pragma once

#include "data.hpp"

int simulate(Flowshop& f, vector<int>& p);
FlowshopSchedule schedule(Flowshop& f, vector<int>& p);
void verify(Flowshop& f, FlowshopSchedule& fs);
