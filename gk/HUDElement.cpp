#include "HUDElement.hpp"

#include <GL/glut.h>

void HUDElement::renderBitmapString(float x, float y, void *font, char *string)
{
  
  char *c;
  // set position to start drawing fonts
  glRasterPos2f(x, y);
  // loop all the characters in the string
  for (c = string; *c != '\0'; c++) 
  {
	glutBitmapCharacter(font, *c);
  }
}

HUDElement::~HUDElement(void)
{
}
