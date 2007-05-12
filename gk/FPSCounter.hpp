#pragma once

class FPSCounter
{
private:
	int frame, time, timebase, heigth, width;
	char s[30];
	void setOrthographicProjection();
	void resetPerspectiveProjection();
	void renderBitmapString(float x, float y, void *font, char *string);
public:
	FPSCounter(int width, int heigth);
	~FPSCounter(void);
	void draw();
};
