#ifndef DISPLAYS_DISPLAY_HPP
#define DISPLAYS_DISPLAY_HPP

#include <cstdarg>
#include <string>

class state;

class display
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

#endif //DISPLAYS_DISPLAY_HPP
