#ifndef WIDGETS_CROSSHAIR_HPP
#define WIDGETS_CROSSHAIR_HPP

#include "widget.hpp"

class crosshair : public widget
{
public:
	crosshair(float size);

	virtual void draw(const state& state) const;

private:
	float size;
};

#endif //WIDGETS_CROSSHAIR_HPP
