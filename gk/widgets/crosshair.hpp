#ifndef WIDGETS_CROSSHAIR_HPP
#define WIDGETS_CROSSHAIR_HPP

#include "display.hpp"
#include "vertex.hpp"

class crosshair : public widget
{
public:
	crosshair(vertex color, float size);

	virtual void draw(const state& state) const;

private:
	vertex color;
	float size;
};

#endif //WIDGETS_CROSSHAIR_HPP
