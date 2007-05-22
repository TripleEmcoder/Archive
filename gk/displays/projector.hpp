#ifndef DISPLAYS_PROJECTOR_HPP
#define DISPLAYS_PROJECTOR_HPP

#include <set>

class display;
class state;

class projector
{
public:
	void add(const display* item);
	void remove(const display* item);

	void draw(const state& state) const;

private:
	std::set<const display*> _displays;

	void setup_orthographic_projection() const;
	void setup_perspective_projection() const;
};

#endif //DISPLAYS_PROJECTOR_HPP
