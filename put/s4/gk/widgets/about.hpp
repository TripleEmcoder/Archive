#ifndef WIDGETS_ABOUT_HPP
#define WIDGETS_ABOUT_HPP

#include "widget.hpp"

class about : public widget
{
public:
	virtual void draw(const state& state) const;
};

#endif //WIDGETS_ABOUT_HPP
