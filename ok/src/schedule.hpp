#pragma once

#include "data.hpp"

int simulate(const Flowshop& f, const vector<int>& p);
FlowshopSchedule schedule(const Flowshop& f, const vector<int>& p);
