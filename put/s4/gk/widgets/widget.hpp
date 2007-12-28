#ifndef WIDGETS_WIDGET_HPP
#define WIDGETS_WIDGET_HPP

#include <cstdarg>
#include <string>

class state;

class widget
{
public:
	virtual void draw(const state& state) const = 0;

protected:
	enum align { left, right, center };

	void write(float x, float y, void* font, float size, std::string format, ...) const;
	void write(float x, float y, std::string format, ...) const;

private:
	void write(float x, float y, void* font, float size, std::string format, va_list arguments) const;
};

#endif //WIDGETS_WIDGET_HPP
