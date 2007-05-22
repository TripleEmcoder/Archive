#pragma once

#include "display.hpp"

class fps_meter : public display
{
public:
	fps_meter();

	virtual void draw(const state& state) const;

private:
	mutable int count, previous;
	mutable float rate;
};
