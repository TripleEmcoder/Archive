#include "movement.hpp"
#include "game.hpp"
#include "engine.hpp"

const float MOUSE_SENSIVITY = 0.5f;
bool keys[255];

void process_active_keys()
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
