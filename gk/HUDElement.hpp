#pragma once

class HUDElement
{
protected:
	void renderBitmapString(float x, float y, float colorRed, float colorGreen, float colorBlue, const char *fmt, ... );
public:
	virtual void drawHUD() = 0;
	virtual ~HUDElement(void);
};
