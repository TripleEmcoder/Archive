#ifndef DISPLAYS_FPS_METER_HPP
#define DISPLAYS_FPS_METER_HPP

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

#endif //DISPLAYS_FPS_METER_HPP
