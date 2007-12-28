#ifndef WIDGETS_PROJECTOR_HPP
#define WIDGETS_PROJECTOR_HPP

#include <set>

#include "vertex.hpp"

class widget;
class state;

class projector
{
public:
	projector(const vertex& color);

	void add(const widget* item);
	void remove(const widget* item);

	void draw(const state& state) const;

private:
	vertex color;

	std::set<const widget*> _widgets;
};

#endif //WIDGETS_PROJECTOR_HPP
