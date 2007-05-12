#include <iostream>
#include <fstream>

#include <windows.h>
#include <GL/gl.h>
#include <GL/glu.h>
#include <GL/glut.h>

#include "map.hpp"
#include "Camera.hpp"
#include "FPSCounter.hpp"
#include "HUDManager.hpp"

map m;
HUDManager* hudManager;
Camera* camera;
FPSCounter* fpsCounter;
int width = 800, heigth = 800;

void pressNormalKey(unsigned char c, int x, int y) 
{
	switch (c)
	{
	case 'w':
		camera->move(Camera::AXIS_Y, 10);
		break;
	case 's':
		camera->move(Camera::AXIS_Y, -10);
		break;
	case 'a':
		camera->move(Camera::AXIS_X, -10);
		break;
	case 'd':
		camera->move(Camera::AXIS_X, 10);
		break;
	}
}

void releaseNormalKey(unsigned char c, int x, int y) {

	switch (c)
	{
	case 'w':
	case 's':
		camera->move(Camera::AXIS_Y, 0);
		break;
	case 'a':
	case 'd':
		camera->move(Camera::AXIS_X, 0);
		break;
	}
}

void processMousePassiveMotion(int x, int y) 
{
	double angle_x = 360 * ((double)x / width - 0.5);
	double angle_y = 360 * ((double)y / width - 0.5);
	camera->rotate(angle_x, -angle_y);
}

void draw(void)
{
	glClearColor(0, 0, 0, 0);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	
	camera->draw();

	glColor3b(20, 40, 60);

	m.draw();

	hudManager->draw();

	glutSwapBuffers();
}

int main(int argc, char* argv[])
{
	std::ifstream ifs("map.xml");
	ifs >> m;
	std::cout << "Map: " << m.name << std::endl;

	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
	glutInitWindowSize(width, heigth);
	glutInitWindowPosition(0, 0);
	glutCreateWindow("gk");

	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluPerspective(50, 1, 1, 50);

	glEnable(GL_LIGHTING);
	glEnable(GL_LIGHT0);
	glEnable(GL_DEPTH_TEST);
	glEnable(GL_COLOR_MATERIAL);
	//glShadeModel(GL_SMOOTH);

	camera = new Camera(0, 2, 10, -70, 0);
	hudManager = new HUDManager(width, heigth);
	fpsCounter = new FPSCounter();
	hudManager->add(fpsCounter);

	glutDisplayFunc(draw);
	glutIdleFunc(draw);

	glutIgnoreKeyRepeat(1);
	glutKeyboardFunc(pressNormalKey);
	glutKeyboardUpFunc(releaseNormalKey);
	
	glutPassiveMotionFunc(processMousePassiveMotion);
	glutMainLoop();
	return 0;
}
