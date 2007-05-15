#include <iostream>
#include <fstream>

#include <windows.h>
#include <GL/gl.h>
#include <GL/glu.h>
#include <GL/glut.h>

#include "objects/world.hpp"
#include "Camera.hpp"
#include "FPSCounter.hpp"
#include "HUDManager.hpp"
#include "Character.hpp"
#include "Crosshair.hpp"
#include "math.hpp"
#include <Newton.h>

world w;
HUDManager* hudManager;
Camera* camera;
FPSCounter* fpsCounter;
Character* character;
Crosshair* crosshair;
int width = 800, height = 800;
bool keyPressed[255];
int timebase;

const float MOUSE_SENSIVITY = 0.5f;

void moveCharacter()
{
	Vector vec;
	
	if (keyPressed[(int)'w'])
		vec[0] = 1.0f;
	else if (keyPressed[(int)'s'])
		vec[0] = -1.0f;
	else
		vec[0] = 0.0f;

	if (keyPressed[(int)'a'])
		vec[2] = -1.0f;
	else if (keyPressed[(int)'d'])
		vec[2] = 1.0f;
	else
		vec[2] = 0.0f;
	
	
	vec[1] = 0;
	vec[3] = 0;

	vec = rotate(vec, 0, camera->getAngleX(), 0);

	character->move(vec);
}

void pressNormalKey(unsigned char c, int x, int y) 
{
	if (c == 27)
		exit(0);
	
	keyPressed[c] = true;
}

void pressSpecialKey(int key, int x, int y) 
{
	
}


void releaseNormalKey(unsigned char c, int x, int y) 
{
	keyPressed[c] = false;
}

void processMousePassiveMotion(int x, int y) 
{
	static bool mouseJump = true;

	if (!mouseJump)
	{
		camera->rotate(MOUSE_SENSIVITY * -(x - width/2) * 3.1416 / 180.0f, MOUSE_SENSIVITY * (y - height/2) * 3.1416 / 180.0f);
		mouseJump = true;
		glutWarpPointer(width/2, height/2);
	}
	else
	{
		mouseJump = false;
	}
}

void processMouse(int button, int state, int x, int y)
{
	if (button == GLUT_RIGHT_BUTTON && state == GLUT_DOWN)
		character->jump();
}

void draw(void)
{
	glClearColor(0, 0, 0, 0);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();

	moveCharacter();

	NewtonUpdate(w.newton.get(), 1.0f/60.0f);
	
	Vector eye = character->getLocation();
	eye[1] += 0.8f;
	camera->setEye(eye);
	camera->draw();

	glColor3b(20, 40, 60);

	w.draw();

	hudManager->draw();

	glutSwapBuffers();
}

int main(int argc, char* argv[])
{
	std::ifstream ifs("map.xml");
	ifs >> w;
	w.compile();

	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
	glutInitWindowSize(width, height);
	glutInitWindowPosition(0, 0);
	glutCreateWindow("gk");

	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluPerspective(50, 1, 1, 50);

	glEnable(GL_LIGHTING);
	glEnable(GL_LIGHT0);
	glEnable(GL_DEPTH_TEST);
	glEnable(GL_COLOR_MATERIAL);
	glShadeModel(GL_SMOOTH);
	glEnable(GL_TEXTURE_2D);

	character = new Character(w.newton.get(), 0.5, 0.5, 0.5, 3, 20, -3);
	Vector location = character->getLocation();
	camera = new Camera(location[0], location[1], location[2], 90.0 * 3.1416 / 180.0, 0);
	fpsCounter = new FPSCounter();
	crosshair = new Crosshair(0.0f, 1.0f, 1.0f, 8.0f);
	hudManager = new HUDManager();
	hudManager->add(fpsCounter);
	hudManager->add(camera);
	hudManager->add(crosshair);
	hudManager->add(character);

	glutDisplayFunc(draw);
	glutIdleFunc(draw);

	glutIgnoreKeyRepeat(1);
	glutSpecialFunc(pressSpecialKey);
	glutKeyboardFunc(pressNormalKey);
	glutKeyboardUpFunc(releaseNormalKey);
	glutWarpPointer(width/2, height/2);
	glutSetCursor(GLUT_CURSOR_NONE);
	glutPassiveMotionFunc(processMousePassiveMotion);
	glutMouseFunc(processMouse);
	
	glutMainLoop();
	return 0;
}
