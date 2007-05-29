#include <iostream>

#include <boost/format.hpp>
#include <boost/lexical_cast.hpp>

#include "game.hpp"
#include "vertex.hpp"
#include "opengl.hpp"

boost::shared_ptr<display_wrapper> display;

boost::shared_ptr<game> instance;

std::vector<bool> monostables(255);
std::vector<bool> bistables(255);

void keyboard_down_callback(unsigned char key, int x, int y) 
{
	if (key == 27)
		throw exit_exception();
	
	monostables[key] = true;
	bistables[key] = !bistables[key];
}

void keyboard_up_callback(unsigned char key, int x, int y) 
{
	monostables[key] = false;	
}

void mouse_event_callback(int button, int state, int x, int y)
{
	instance->process_mouse_event(button, state, x, y);
}

void mouse_motion_callback(int x, int y) 
{
	instance->process_mouse_motion(x, y);
}

void reshape_callback(int width, int height)
{
	instance->update_viewport(width, height);
}

void display_callback()
{
	instance->process_monostable_keys(monostables);
	instance->process_bistable_keys(bistables);

	instance->process_physics();

	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	instance->draw_level(vertex(0, 0, 0), 0, 0);
	instance->draw_projector();

	glutSwapBuffers();
}

void setup_callbacks()
{
	glutReshapeFunc(reshape_callback);
	glutDisplayFunc(display_callback);
	glutIdleFunc(display_callback);

	glutKeyboardFunc(keyboard_down_callback);
	glutKeyboardUpFunc(keyboard_up_callback);
	glutIgnoreKeyRepeat(1);

	glutMouseFunc(mouse_event_callback);
	glutPassiveMotionFunc(mouse_motion_callback);
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

	try
	{
		if (strcmp(argv[1], "window") == 0)
			display.reset(new window_wrapper("gk", 0, 0, width, height));
		
		else if (strcmp(argv[1], "fullscreen") == 0)
			display.reset(new fullscreen_wrapper(width, height, 16, 0));

		else
			throw std::exception("Incorrect display type.");

		GLenum error = glewInit();

		if (error != GLEW_OK)
		{
			std::string message = (boost::format("%1%.") % glewGetErrorString(error)).str();
			throw std::exception(message.c_str());
		}
		
		glEnable(GL_DEPTH_TEST);	

		instance.reset(new game("level.xml"));

		setup_callbacks();

		std::cerr << "Running..." << std::endl;
		glutMainLoop();
	}
	catch (std::exception& exception)
	{
		std::cerr << "Fatal error:" << std::endl;
		std::cerr << exception.what() << std::endl;
		return 2;
	}
	catch (exit_exception& exception)
	{
		std::cerr << "User requested shutdown." << std::endl;
	}

	return 0;
}
