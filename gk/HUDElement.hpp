#pragma once

class HUDElement
{
protected:
	void renderBitmapString(float x, float y, void *font, char *string);
public:
	virtual void draw() = 0;
	virtual ~HUDElement(void);
};
