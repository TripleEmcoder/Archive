#ifndef WIDGETS_FPS_METER_HPP
#define WIDGETS_FPS_METER_HPP

#include "widget.hpp"

class fps_meter : public widget
{
public:
	fps_meter();

	virtual void draw(const state& state) const;

private:
	mutable int count, previous;
	mutable float rate;
};

#endif //WIDGETS_FPS_METER_HPP
