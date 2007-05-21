#include <iostream>
#include <fstream>

#include "objects/world.hpp"
#include "Camera.hpp"
#include "FPSCounter.hpp"
#include "HUDManager.hpp"
#include "Character.hpp"
#include "Crosshair.hpp"
#include "math.hpp"
#include "engine.hpp"

GLuint list;
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

	if (c=='l')
		glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);

	if (c=='f')
		glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
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
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();

	moveCharacter();

	int time = glutGet(GLUT_ELAPSED_TIME) - timebase;
	timebase += time;

	NewtonUpdate(w.newton(), time / 1000.0f);
	//NewtonUpdate(w.newton(), 1.0f / 40.0f);
	
	Vector eye = character->getLocation();
	eye[1] += 0.8f;
	camera->setEye(eye);
	camera->draw();

	//glColor3b(20, 40, 60);

	w.draw();
	//glCallList(list);

	hudManager->draw();

	glutSwapBuffers();
}

int main(int argc, char* argv[])
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
	glutInitWindowSize(width, height);
	glutInitWindowPosition(0, 0);
	glutCreateWindow("gk");

	std::cerr << "Opening..." << std::endl;
	std::ifstream ifs("map.xml");

	std::cerr << "Reading..." << std::endl;
	ifs >> w;

	std::cerr << "Compiling..." << std::endl;
	w.compile();

	//glClearColor(0.0, 0.0, 0.0, 0.0); 	   // Black Background
	//glShadeModel(GL_SMOOTH);                 // Enables Smooth Color Shading
	//glClearDepth(1.0);                       // Depth Buffer Setup
	//glEnable(GL_DEPTH_TEST);                 // Enable Depth Buffer
	//glDepthFunc(GL_LESS);		           // The Type Of Depth Test To Do
	//glCullFace(GL_FRONT);
	//glEnable(GL_CULL_FACE);
	//glEnable(GL_TEXTURE_2D);                     // Enable Texture Mapping

	//glHint(GL_PERSPECTIVE_CORRECTION_HINT, GL_NICEST);   //Realy Nice perspective calculations
	//glEnable(GL_LIGHT0);
	//glEnable(GL_LIGHTING);

	//GLfloat direction[]= { 0.0f, 0.0f, -1.0f};
	//GLfloat position[]= { 0.0f, 0.0f, 2.0f, 1.0f };
	//glLightf (GL_LIGHT0, GL_SPOT_CUTOFF, 10);
	//glLightfv(GL_LIGHT0, GL_SPOT_DIRECTION, direction);
	//glLightfv(GL_LIGHT0, GL_POSITION, position);	
	//glEnable(GL_LIGHT0);
	//glEnable(GL_LIGHTING);
	
	glEnable(GL_DEPTH_TEST);
	//glEnable(GL_COLOR_MATERIAL);
	glShadeModel(GL_SMOOTH);
	glEnable(GL_TEXTURE_2D);
	glEnable(GL_NORMALIZE);

	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluPerspective(50, 1, 0.1, 100);

	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();

	character = new Character(w.newton(), 0.6, 0.9, 0.6, 1.6, 10, 0.32);
	//character = new Character(w.newton(), 40, 90, 40, 80, 500, 16);
	Vector location = character->getLocation();
	camera = new Camera(location[0], location[1], location[2], -180.0 * 3.1416 / 180.0, 0);
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

	list = glGenLists(1);
	glNewList(list, GL_COMPILE);
	//w.draw();
	glEndList();

	timebase = glutGet(GLUT_ELAPSED_TIME);

	glutMainLoop();
	return 0;
}
