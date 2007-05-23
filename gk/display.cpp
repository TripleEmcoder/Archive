#include "display.hpp"
#include "engine.hpp"

#include <boost/format.hpp>

bool setup_window(std::string title, int x, int y, int width, int height)
{
	glutInitWindowSize(width, height);
	glutInitWindowPosition(x, y);
	
	int window = glutCreateWindow(title.c_str());

	if (window != 0)
		atexit(cleanup_window);

	return window != 0;
}

void cleanup_window()
{
	glutDestroyWindow(glutGetWindow());
}

bool setup_fullscreen(int width, int height, int depth, int frequency)
{
	glutGameModeString((boost::format("%1%x%2%:%3%")
		% width % height % depth).str().c_str());

	bool possible = glutGameModeGet(GLUT_GAME_MODE_POSSIBLE);

	if (possible)
	{
		glutEnterGameMode();
		atexit(cleanup_fullscreen);
	}

	return possible;
}

void cleanup_fullscreen()
{
	glutLeaveGameMode();
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