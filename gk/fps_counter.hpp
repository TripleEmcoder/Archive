#pragma once

class fps_counter
{
private:
	int frame, time, timebase, heigth, width;
	char s[30];
	void setOrthographicProjection();
	void resetPerspectiveProjection();
	void renderBitmapString(float x, float y, void *font, char *string);
public:
	fps_counter(int width, int heigth);
	~fps_counter(void);
	void draw();
};
