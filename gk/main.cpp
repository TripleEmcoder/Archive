#include "game.hpp"
#include "display.hpp"
#include "movement.hpp"
#include "state.hpp"
#include "engine.hpp"

#include <iostream>
#include <fstream>

#include <boost/lexical_cast.hpp>

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

void setup_widgets()
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

void setup_lights()
{
	GLfloat global[]    = {  0.0f,  0.0f,  0.0f,  1.0f };
	GLfloat position[]  = {  0.0f,  0.0f,  2.0f,  1.0f };
	GLfloat ambient[]   = {  0.0f,  0.0f,  0.0f,  1.0f };
	GLfloat diffuse[]   = {  0.4f,  0.4f,  0.4f,  1.0f };
	GLfloat specular[]  = {  0.4f,  0.4f,  0.4f,  1.0f };
	GLfloat direction[] = {  0.0f,  0.0f, -1.0f        };

	glLightModelfv(GL_LIGHT_MODEL_AMBIENT, global);
	
	glLightfv(GL_LIGHT0, GL_POSITION, position);
	glLightfv(GL_LIGHT0, GL_AMBIENT, ambient);
	glLightfv(GL_LIGHT0, GL_DIFFUSE, diffuse);
	glLightfv(GL_LIGHT0, GL_SPECULAR, specular);

	glLightfv(GL_LIGHT0, GL_SPOT_DIRECTION, direction);
	glLightf (GL_LIGHT0, GL_SPOT_CUTOFF, 30);

	glEnable(GL_LIGHT0);

	//glEnable(GL_LIGHTING);
}

void draw()
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glLoadIdentity();

	state state;
	state.camera = camera;

	process_active_keys();

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
	
	if (argc != 3)
	{
		std::cerr << "Parameters:" << std::endl;
		std::cerr << "\t(window|fullscreen) - widget mode" << std::endl;
		std::cerr << "\t(\\d+) - widget width" << std::endl;
		std::cerr << "\t(\\d+) - widget height" << std::endl;
		exit(1);
	}

	int width = boost::lexical_cast<int>(argv[1]);
	int height = boost::lexical_cast<int>(argv[2]);

	if (argv[0] == "window")
		setup_window("gk", 0, 0, width, height);
	
	else if (argv[0] == "fullscreen")
		setup_fullscreen(width, height, 16);

	GLenum error = glewInit();

	if (error != GLEW_OK) 
		std::cerr << glewGetErrorString(error) << "." << std::endl;

	glEnable(GL_DEPTH_TEST);
	glEnable(GL_TEXTURE_2D);
	glEnable(GL_NORMALIZE);
	glShadeModel(GL_SMOOTH);
	
	load_map("map.xml");
	
	setup_widgets();
	setup_lights();
	setup_callbacks();

	glutMainLoop();
	return 0;
}
