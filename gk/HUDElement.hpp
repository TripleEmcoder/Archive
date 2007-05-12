#pragma once

class HUDElement
{
protected:
	void renderBitmapString(float x, float y, const char *fmt, ... );
public:
	virtual void drawHUD() = 0;
	virtual ~HUDElement(void);
};
