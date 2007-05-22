#include "world.hpp"
#include "objects/character.hpp"
#include "Camera.hpp"
#include "Character.hpp"

#include "projector.hpp"
#include "fps_meter.hpp"
#include "crosshair.hpp"
#include "compass.hpp"

#include "state.hpp"
#include "engine.hpp"

#include <iostream>
#include <fstream>

bool keys[255];

world w;
projector p;
fps_meter f;
crosshair c(vertex(0.0f, 1.0f, 1.0f), 8.0f);
compass s(50);

Camera* camera;
Character* character;

const float MOUSE_SENSIVITY = 0.5f;

void moveCharacter()
{
	Vector vec;
	
	if (keys[(int)'w'])
		vec[0] = 1.0f;
	else if (keys[(int)'s'])
		vec[0] = -1.0f;
	else
		vec[0] = 0.0f;

	if (keys[(int)'a'])
		vec[2] = -1.0f;
	else if (keys[(int)'d'])
		vec[2] = 1.0f;
	else
		vec[2] = 0.0f;
	
	vec[1] = 0;
	vec[3] = 0;

	vec = rotate(vec, 0, camera->getAngleX(), 0);

	character->move(vec);
}


void process_key_down(unsigned char key, int x, int y) 
{
	if (key == 27)
		exit(0);
	
	keys[key] = true;
}

void process_key_up(unsigned char key, int x, int y) 
{
	keys[key] = false;

	if (key == 'l')
		glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);

	if (key == 'f')
		glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
}

void process_mouse_event(int button, int state, int x, int y)
{
	if (button == GLUT_RIGHT_BUTTON && state == GLUT_DOWN)
		character->jump();
}

void process_mouse_motion(int x, int y) 
{
	static bool jump = true;

	if (!jump)
	{
		int w = glutGet(GLUT_WINDOW_WIDTH);
		int h = glutGet(GLUT_WINDOW_HEIGHT);
		camera->rotate(MOUSE_SENSIVITY * -(x - w/2) * 3.1416 / 180.0f, MOUSE_SENSIVITY * (y - h/2) * 3.1416 / 180.0f);
		jump = true;
		glutWarpPointer(w/2, h/2);
	}
	else
	{
		jump = false;
	}
}

void draw(void)
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glLoadIdentity();

	state state;
	state.camera = camera;

	moveCharacter();

	static int timebase = glutGet(GLUT_ELAPSED_TIME);
	int time = glutGet(GLUT_ELAPSED_TIME) - timebase;
	timebase += time;

	NewtonUpdate(w.newton(), time / 1000.0f);
	//NewtonUpdate(w.newton(), 1.0f);
	
	Vector eye = character->getLocation();
	eye[1] += 0.8f;
	camera->setEye(eye);
	camera->set(state);

	w.draw(state);
	p.draw(state);

	glutSwapBuffers();
}

void reshape_window(int w, int h)
{
	glutWarpPointer(w/2, h/2);

	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluPerspective(50, w/h, 0.1, 500);

	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
}

int setup_window(std::string title, int x, int y, int w, int h)
{
	glutInitWindowSize(w, h);
	glutInitWindowPosition(x, y);
	return glutCreateWindow(title.c_str());
}

void load_map(std::string name)
{
	std::cerr << "Opening..." << std::endl;
	std::ifstream ifs(name.c_str());

	std::cerr << "Reading..." << std::endl;
	ifs >> w;

	std::cerr << "Compiling..." << std::endl;
	w.compile();

	std::cerr << "Done." << std::endl;
}

void setup_displays()
{
	character = new Character(w.newton(), 0.4, 0.9, 0.4, 0, 1.5, 0);
	//character = new Character(w.newton(), 0.4, 0.9, 0.4, 80, 288, 16);
	//character = new Character(w.newton(), 40, 90, 40, 80, 500, 16);
	//character = new Character(w.newton(), w.player.size.x, w.player.size.y, w.player.size.z, w.player.translation.x, w.player.translation.y, w.player.translation.z);
	Vector location = character->getLocation();
	camera = new Camera(location[0], location[1], location[2], -180.0 * 3.1416 / 180.0, 0);
	p.add(&f);
	p.add(&c);
	p.add(&s);
	p.add(character);
	p.add(camera);
}

void setup_lighting()
{
	//GLfloat direction[]= { 0.0f, 0.0f, -1.0f};
	//GLfloat position[]= { 0.0f, 0.0f, 2.0f, 1.0f };
	//glLightf (GL_LIGHT0, GL_SPOT_CUTOFF, 10);
	//glLightfv(GL_LIGHT0, GL_SPOT_DIRECTION, direction);
	//glLightfv(GL_LIGHT0, GL_POSITION, position);
	//glEnable(GL_LIGHT0);
	//glEnable(GL_LIGHTING);
}

void setup_callbacks()
{
	glutReshapeFunc(reshape_window);
	glutDisplayFunc(draw);
	glutIdleFunc(draw);

	glutKeyboardFunc(process_key_down);
	glutKeyboardUpFunc(process_key_up);
	glutIgnoreKeyRepeat(1);

	glutMouseFunc(process_mouse_event);
	glutPassiveMotionFunc(process_mouse_motion);
	glutSetCursor(GLUT_CURSOR_NONE);
}

int main(int argc, char* argv[])
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE);
	
	setup_window("gk", 0, 0, 800, 600);

	GLenum error = glewInit();

	if (error != GLEW_OK) 
		std::cerr << glewGetErrorString(error) << std::endl;

	glEnable(GL_DEPTH_TEST);
	glEnable(GL_TEXTURE_2D);
	glEnable(GL_NORMALIZE);

	glShadeModel(GL_SMOOTH);
	load_map("map.xml");
	
	setup_displays();
	setup_lighting();
	setup_callbacks();

	glutMainLoop();
	return 0;
}
