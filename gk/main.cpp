#include "game.hpp"
#include "display.hpp"
#include "movement.hpp"
#include "state.hpp"
#include "opengl.hpp"

#include <iostream>
#include <fstream>

#include <boost/lexical_cast.hpp>

void load_level(std::string name)
{
	std::cerr << "Opening..." << std::endl;
	std::ifstream ifs(name.c_str());

	std::cerr << "Reading..." << std::endl;
	ifs >> w;

	std::cerr << "Compiling..." << std::endl;
	w.compile();
}

void setup_widgets()
{
	character = new Character(w.world(), 0.4, 0.9, 0.4, -40, 1.5, 20);
	//character = new Character(w.world(), 0.4, 0.9, 0.4, 80, 288, 16);
	//character = new Character(w.world(), 40, 90, 40, 80, 500, 16);
	//character = new Character(w.world(), w.player.size.x, w.player.size.y, w.player.size.z, w.player.translation.x, w.player.translation.y, w.player.translation.z);
	Vector location = character->getLocation();
	camera = new Camera(location[0], location[1], location[2], 0, 0);
	camera->setCameraInternals(50, 1024.0/768.0, 0.1, 50);
	p.add(&f);
	p.add(&c);
	p.add(&s);
	p.add(character);
	p.add(camera);
}

GLfloat position[]  = {  0.0f,  2.0f,  0.0f,  1.0f };
GLfloat direction[] = {  0.0f, -1.0f, -1.0f        };

void setup_lights()
{
	GLfloat global[]    = {  0.5f,  0.5f,  0.5f,  1.0f };
	GLfloat ambient[]   = {  0.8f,  0.8f,  0.8f,  1.0f };
	GLfloat diffuse[]   = {  0.4f,  0.4f,  0.4f,  1.0f };
	GLfloat specular[]  = {  0.4f,  0.4f,  0.4f,  1.0f };

	glLightModelfv(GL_LIGHT_MODEL_AMBIENT, global);	

	glLightfv(GL_LIGHT0, GL_AMBIENT, ambient);
	glLightfv(GL_LIGHT0, GL_DIFFUSE, diffuse);
	glLightfv(GL_LIGHT0, GL_SPECULAR, specular);

	glLightfv(GL_LIGHT0, GL_SPOT_DIRECTION, direction);
	glLightf (GL_LIGHT0, GL_SPOT_CUTOFF, 30);

	glLightfv(GL_LIGHT0, GL_POSITION, position);

	glEnable(GL_LIGHT0);

	glEnable(GL_LIGHTING);
}

void process_physics()
{
	static int time = glutGet(GLUT_ELAPSED_TIME);
	int elapsed = glutGet(GLUT_ELAPSED_TIME) - time;

	NewtonUpdate(w.world().id(), elapsed / 1000.0f);
	
	time = glutGet(GLUT_ELAPSED_TIME);
}

void draw_scene(const vertex& offset, float x, float y)
{
	Vector position = character->getLocation();
	position[1] += 0.8f;

	position[0] += offset.x;
	position[1] += offset.y;
	position[2] += offset.z;

	camera->setPosition(position);

	x = degrees_to_radians(x);
	y = degrees_to_radians(y);

	camera->rotate(x, y);

	state state;
	state.camera = camera;

	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	camera->set();
	w.draw(state);

	camera->rotate(-x, -y);
}

void draw_everything()
{
	process_active_keys();
	process_physics();

	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	draw_scene(vertex(0, 0, 0), 0, 0);

	state state;
	state.camera = camera;

	p.draw(state);
	glutSwapBuffers();
}

void setup_callbacks()
{
	glutReshapeFunc(reshape_window);
	glutDisplayFunc(draw_everything);
	glutIdleFunc(draw_everything);

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
	
	if (argc != 4)
	{
		std::cerr << "Parameters:" << std::endl;
		std::cerr << "\t(window|fullscreen) - display type" << std::endl;
		std::cerr << "\t(\\d+) - display width" << std::endl;
		std::cerr << "\t(\\d+) - display height" << std::endl;
		return 1;
	}

	int width = boost::lexical_cast<int>(argv[2]);
	int height = boost::lexical_cast<int>(argv[3]);

	if (strcmp(argv[1], "window") == 0)
		setup_window("gk", 0, 0, width, height);
	
	else if (strcmp(argv[1], "fullscreen") == 0)
		setup_fullscreen(width, height, 16, 0);

	else
	{
		std::cerr << "Incorrect display type." << std::endl;
		return 2;
	}

	GLenum error = glewInit();

	if (error != GLEW_OK)
	{
		std::cerr << glewGetErrorString(error) << "." << std::endl;
		return 3;
	}
	
	load_level("level.xml");
	
	setup_widgets();
	setup_lights();
	setup_callbacks();

	glEnable(GL_DEPTH_TEST);

	shader_wrapper v(GL_VERTEX_SHADER, "vertex.c");
	shader_wrapper f(GL_FRAGMENT_SHADER, "fragment.c");

	program_wrapper p;
	p.attach(v);
	p.attach(f);
	p.link();
	//p.use();

	std::cerr << "Running..." << std::endl;
	glutMainLoop();
	return 0;
}
