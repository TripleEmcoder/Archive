#ifndef DISPLAYS_COMPASS_HPP
#define DISPLAYS_COMPASS_HPP

#include "display.hpp"

class compass : public display
{
public:
	compass(float radius);

	virtual void draw(const state& state) const;

private:
	float radius;

	void write(float x, float y, std::string text) const;
};

#endif //DISPLAYS_COMPASS_HPP
