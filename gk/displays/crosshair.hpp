#ifndef DISPLAYS_CROSSHAIR_HPP
#define DISPLAYS_CROSSHAIR_HPP

#include "display.hpp"
#include "vertex.hpp"

class crosshair : public display
{
public:
	crosshair(vertex color, float size);

	virtual void draw(const state& state) const;

private:
	vertex color;
	float size;
};

#endif //DISPLAYS_CROSSHAIR_HPP
