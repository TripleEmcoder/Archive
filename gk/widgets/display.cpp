#include "display.hpp"
#include "engine.hpp"

#include <cstdio>
#include <cstring>

void widget::write(float x, float y, void* font, float size, std::string format, ...) const 
{
	va_list arguments;

	va_start(arguments, format);
	write(x, y, font, size, format, arguments);
	va_end(arguments);
}

void widget::write(float x, float y, std::string format, ...) const 
{
	va_list arguments;

	va_start(arguments, format);
	write(x, y, GLUT_BITMAP_8_BY_13, 0, format, arguments);
	va_end(arguments);
}

void widget::write(float x, float y, void* font, float size, std::string format, va_list arguments) const 
{
	char text[1024];
	
	vsprintf(text, format.c_str(), arguments);

	switch ((int)font)
	{
	case GLUT_BITMAP_8_BY_13:
	case GLUT_BITMAP_9_BY_15:

		_ASSERTE(size == 0);
		glPushAttrib(GL_CURRENT_BIT);
		glRasterPos3f(x, y, 0);

		for (int index=0; index<strlen(text); index++) 
			glutBitmapCharacter(font, text[index]);

		glPopAttrib();
		break;

	case GLUT_STROKE_ROMAN:
	case GLUT_STROKE_MONO_ROMAN:

		glPushMatrix();
		glTranslatef(x, y, 0);
		glScalef(size, size, 0);

		for (int index=0; index<strlen(text); index++) 
			glutStrokeCharacter(font, text[index]);

		glPopMatrix();
	}
}

