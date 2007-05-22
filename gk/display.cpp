#include "display.hpp"
#include "engine.hpp"

int setup_window(std::string title, int x, int y, int width, int height)
{
	glutInitWindowSize(width, height);
	glutInitWindowPosition(x, y);
	return glutCreateWindow(title.c_str());
}

void reshape_window(int width, int height)
{
	glutWarpPointer(width/2, height/2);

	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluPerspective(50, width/height, 0.1, 500);

	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
}

void setup_fullscreen(int width, int height, int depth)
{
	glutEnterGameMode();
}
