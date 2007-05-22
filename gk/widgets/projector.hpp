#ifndef WIDGETS_PROJECTOR_HPP
#define WIDGETS_PROJECTOR_HPP

#include <set>

class widget;
class state;

class projector
{
public:
	void add(const widget* item);
	void remove(const widget* item);

	void draw(const state& state) const;

private:
	std::set<const widget*> _widgets;

	void setup_orthographic_projection() const;
	void setup_perspective_projection() const;
};

#endif //WIDGETS_PROJECTOR_HPP
