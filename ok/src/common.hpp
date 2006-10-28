#pragma once

#include "data.hpp"

int schedule(Flowshop& f, FlowshopSchedule& fs, vector<int>& p);
bool verify(Flowshop& f, FlowshopSchedule& fs);
