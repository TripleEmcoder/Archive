#include <iostream>
#include <fstream>

#include <windows.h>
#include <GL/gl.h>
#include <GL/glu.h>
#include <GL/glut.h>

#include "map.hpp"
#include "camera.hpp"
#include "fps_counter.hpp"

map m;
camera* cam;
fps_counter* fps;
int width = 800, heigth = 800;

void pressNormalKey(unsigned char c, int x, int y) 
{
	switch (c)
	{
	case 'w':
		cam->move(camera::AXIS_X, 10);
		break;
	case 's':
		cam->move(camera::AXIS_X, -10);
		break;
	case 'a':
		cam->move(camera::AXIS_Y, -10);
		break;
	case 'd':
		cam->move(camera::AXIS_Y, 10);
		break;
	}
}

void releaseNormalKey(unsigned char c, int x, int y) {

	switch (c)
	{
	case 'w':
	case 's':
		cam->move(camera::AXIS_X, 0);
		break;
	case 'a':
	case 'd':
		cam->move(camera::AXIS_Y, 0);
		break;
	}
}

void processMousePassiveMotion(int x, int y) 
{
	double angle_x = 360 * ((double)x / width - 0.5);
	double angle_y = 360 * ((double)y / width - 0.5);
	cam->rotate(angle_x, -angle_y);
}

void draw(void)
{
	glClearColor(0, 0, 0, 0);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	
	cam->draw();

	glColor3b(20, 40, 60);

	m.draw();

	fps->draw();

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

	cam = new camera(10, 0, 10, -140, 0);
	fps = new fps_counter(width, heigth);

	glutDisplayFunc(draw);
	glutIdleFunc(draw);

	glutIgnoreKeyRepeat(1);
	glutKeyboardFunc(pressNormalKey);
	glutKeyboardUpFunc(releaseNormalKey);
	
	glutPassiveMotionFunc(processMousePassiveMotion);
	glutMainLoop();
	return 0;
}
