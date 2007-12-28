#ifndef WIDGETS_COMPASS_HPP
#define WIDGETS_COMPASS_HPP

#include "widget.hpp"

class compass : public widget
{
public:
	compass(float radius);

	virtual void draw(const state& state) const;

private:
	float radius;

	void write(float x, float y, std::string text) const;
};

#endif //WIDGETS_COMPASS_HPP
