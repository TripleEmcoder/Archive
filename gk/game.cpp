#include "game.hpp"

#include <iostream>
#include <fstream>

#include <boost/format.hpp>

game::game(std::string name)
:
	camera(0, 0),
	projector(vertex(0, 1, 1)),
	crosshair(8),
	compass(50),
	state(camera)
{
	load_level(name);
	setup_widgets();
	setup_lights();
	setup_shaders();
}

game::~game()
{
#ifdef _DEBUG
	std::cerr << "Shutting down game." << std::endl;
#endif
}

void game::load_level(std::string name)
{
	std::cerr << "Loading level \"" << name << "\"..." << std::endl;
	std::ifstream input(name.c_str());

	if (input.fail())
		throw std::exception((boost::format(
			"Failed to load level \"%1%\".") % name).str().c_str());

	input >> level;
	level.compile();
}

void game::setup_widgets()
{
	character.reset(new Character(level.world(), 0.4, 0.9, 0.4, -40, 1.5, 20));
	Vector location = character->getLocation();
	projector.add(character.get());

	projector.add(&camera);
	projector.add(&fps_meter);
	projector.add(&crosshair);
	projector.add(&compass);
}

void game::setup_lights()
{
	//GLfloat global[]    = {  0.5f,  0.5f,  0.5f,  1.0f };
	GLfloat global[]    = {  0.0f,  0.0f,  0.0f,  0.0f };
	GLfloat ambient[]   = {  0.8f,  0.8f,  0.8f,  1.0f };
	GLfloat diffuse[]   = {  0.4f,  0.4f,  0.4f,  1.0f };
	GLfloat specular[]  = {  0.4f,  0.4f,  0.4f,  1.0f };

	GLfloat position[]  = {  0.0f,  3.0f,  0.0f,  1.0f };
	GLfloat direction[] = {  0.0f,  -1.0f, 0.0f        };

	glLightModelfv(GL_LIGHT_MODEL_AMBIENT, global);	

	glLightfv(GL_LIGHT0, GL_AMBIENT, ambient);
	glLightfv(GL_LIGHT0, GL_DIFFUSE, diffuse);
	glLightfv(GL_LIGHT0, GL_SPECULAR, specular);

	glLightfv(GL_LIGHT0, GL_SPOT_DIRECTION, direction);
	glLightf (GL_LIGHT0, GL_SPOT_CUTOFF, 30);
	glLightf (GL_LIGHT0, GL_SPOT_EXPONENT, 5);

	glLightfv(GL_LIGHT0, GL_POSITION, position);

	glEnable(GL_LIGHT0);

	glEnable(GL_LIGHTING);
}

void game::setup_shaders()
{
	//static shader_wrapper v(GL_VERTEX_SHADER, "vertex.c");
	//static shader_wrapper f(GL_FRAGMENT_SHADER, "fragment.c");

	//static program_wrapper p;
	//p.attach(v);
	//p.attach(f);
	//p.link();
//	p.use();
}

void game::process_physics()
{
	static int time = glutGet(GLUT_ELAPSED_TIME);
	int elapsed = glutGet(GLUT_ELAPSED_TIME) - time;

	NewtonUpdate(level.world().id(), elapsed / 1000.0f);
	
	time = glutGet(GLUT_ELAPSED_TIME);
}

void game::draw_level(const vertex& offset, float x, float y)
{
	Vector position = character->getLocation();
	position[1] += 0.8f;

	position[0] += offset.x;
	position[1] += offset.y;
	position[2] += offset.z;

	camera.setPosition(position);

	x = degrees_to_radians(x);
	y = degrees_to_radians(y);

	camera.rotate(x, y);

	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	camera.set();
	level.draw(state);

	camera.rotate(-x, -y);
}

void game::draw_projector()
{
	projector.draw(state);
}

void game::process_monostable_keys(const std::vector<bool>& keys)
{
	Vector vec;

	if (keys['w'])
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

	vec = rotate(vec, 0, camera.getAngleX(), 0);

	character->move(vec);
}

void game::process_bistable_keys(const std::vector<bool>& keys)
{
	switch (keys['p'])
	{
	case true:
		glPolygonMode(GL_FRONT_AND_BACK, GL_LINE); break;
	case false:
		glPolygonMode(GL_FRONT_AND_BACK, GL_FILL); break;
	}

	switch (keys['l'])
	{
	case true:
		glEnable(GL_LIGHTING); break;
	case false:
		glDisable(GL_LIGHTING); break;
	}

	switch (keys['m'])
	{
	case true:
		state.settings[LIGHTING_MODE] = LIGHTING_MODE_VERTEX; break;
	case false:
		state.settings[LIGHTING_MODE] = LIGHTING_MODE_LIGHTMAP; break;
	}
}

const float MOUSE_SENSIVITY = 0.5f;

void game::process_mouse_event(int button, int state, int x, int y)
{
	if (button == GLUT_RIGHT_BUTTON && state == GLUT_DOWN)
		character->jump();
}

void game::process_mouse_motion(int x, int y) 
{
	static bool jump = true;

	if (!jump)
	{
		int w = glutGet(GLUT_WINDOW_WIDTH);
		int h = glutGet(GLUT_WINDOW_HEIGHT);
		camera.rotate(MOUSE_SENSIVITY * -(x - w/2) * 3.1416 / 180.0f, MOUSE_SENSIVITY * (y - h/2) * 3.1416 / 180.0f);
		jump = true;
		glutWarpPointer(w/2, h/2);
	}
	else
	{
		jump = false;
	}
}

void game::update_viewport(int width, int height)
{
	if (width == 0 || height == 0)
		return;

	glutWarpPointer(width/2, height/2);

	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluPerspective(50, width/height, 0.1, 50);

	camera.setCameraInternals(50, width/height, 0.1, 50);
}
