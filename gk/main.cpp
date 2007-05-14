#include <iostream>
#include <fstream>

#include <windows.h>
#include <GL/gl.h>
#include <GL/glu.h>
#include <GL/glut.h>

#include "objects/map.hpp"
#include "Camera.hpp"
#include "FPSCounter.hpp"
#include "HUDManager.hpp"
#include "Character.hpp"
#include "math.hpp"
#include <Newton.h>

map m;
NewtonWorld* nWorld;
HUDManager* hudManager;
Camera* camera;
FPSCounter* fpsCounter;
Character* character;
int width = 800, heigth = 800;
bool keyPressed[255];

const float MOUSE_SENSIVITY = 0.5f;

void setCharacterForce()
{
	Vector force;
	
	if (keyPressed[(int)'w'])
		force[0] = 15.0f;
	else if (keyPressed[(int)'s'])
		force[0] = -15.0f;
	else
		force[0] = 0.0f;

	if (keyPressed[(int)'a'])
		force[2] = -15.0f;
	else if (keyPressed[(int)'d'])
		force[2] = 15.0f;
	else
		force[2] = 0.0f;
	
	
	force[1] = 0;
	force[3] = 0;

	//force = prod(force, camera->getRotationMatrix());

	force = prod(force, camera->getRotationMatrix());

	character->setForce(force);
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
	static int oldX, oldY;
	static bool mouseJump = true;

	if (!mouseJump)
	{
		camera->rotate(MOUSE_SENSIVITY * -(x - oldX) * 3.1416 / 180.0f, MOUSE_SENSIVITY * (y - oldY) * 3.1416 / 180.0f);
		oldX = x;
		oldY = y;
		mouseJump = true;
		glutWarpPointer(width/2, heigth/2);
	}
	else
	{
		oldX = x;
		oldY = y;
		mouseJump = false;
	}
}

void draw(void)
{
	glClearColor(0, 0, 0, 0);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();

	setCharacterForce();

	NewtonUpdate(nWorld, 1.0f/60.0f);
	
	camera->setEye(character->getLocation());
	//camera->setDirection(character->getDirection());
	camera->draw();

	glColor3b(20, 40, 60);

	m.draw();

	hudManager->draw();

	glutSwapBuffers();
}

void cleanUp()
{
	NewtonDestroy(nWorld);
}

int main(int argc, char* argv[])
{
	std::ifstream ifs("map.xml");
	ifs >> m;
	std::cerr << "Map: " << m.name << std::endl;

	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
	glutInitWindowSize(width, heigth);
	glutInitWindowPosition(0, 0);
	glutCreateWindow("gk");

	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluPerspective(50, 1, 1, 50);

	glEnable(GL_LIGHTING);
	//glEnable(GL_LIGHT0);
	glEnable(GL_DEPTH_TEST);
	glEnable(GL_COLOR_MATERIAL);
	glShadeModel(GL_SMOOTH);
	glEnable(GL_TEXTURE_2D);

	nWorld = NewtonCreate(NULL, NULL);
	m.build(nWorld);
	atexit(cleanUp); 

	character = new Character(nWorld, 2.0, 1.8, 2.0, 0, 2, 10);
	camera = new Camera(0, 2, 10, 90.0 * 3.1416 / 180.0, 0);
	fpsCounter = new FPSCounter();
	hudManager = new HUDManager(width, heigth);
	hudManager->add(fpsCounter);
	hudManager->add(camera);

	glutDisplayFunc(draw);
	glutIdleFunc(draw);

	glutIgnoreKeyRepeat(1);
	glutSpecialFunc(pressSpecialKey);
	glutKeyboardFunc(pressNormalKey);
	glutKeyboardUpFunc(releaseNormalKey);
	glutWarpPointer(width/2, heigth/2);
	glutSetCursor(GLUT_CURSOR_CROSSHAIR);
	
	glutPassiveMotionFunc(processMousePassiveMotion);
	glutMainLoop();
	return 0;
}
