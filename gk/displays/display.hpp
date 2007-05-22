#ifndef DISPLAYS_DISPLAY_HPP
#define DISPLAYS_DISPLAY_HPP

class state;

class display
{
public:
	virtual void draw(const state& state) const = 0;

protected:
	void renderBitmapString(float x, float y, float colorRed, float colorGreen, float colorBlue, const char *fmt, ... ) const;
};

#endif //DISPLAYS_DISPLAY_HPP
