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

	std::cerr << "Done." << std::endl;
}

void setup_widgets()
{
	character = new Character(w.world(), 0.4, 0.9, 0.4, -40, 1.5, 20);
	//character = new Character(w.world(), 0.4, 0.9, 0.4, 80, 288, 16);
	//character = new Character(w.world(), 40, 90, 40, 80, 500, 16);
	//character = new Character(w.world(), w.player.size.x, w.player.size.y, w.player.size.z, w.player.translation.x, w.player.translation.y, w.player.translation.z);
	Vector location = character->getLocation();
	camera = new Camera(location[0], location[1], location[2], -180.0 * 3.1416 / 180.0, 0);
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
	
	glLightfv(GL_LIGHT0, GL_POSITION, position);
	glLightfv(GL_LIGHT0, GL_AMBIENT, ambient);
	glLightfv(GL_LIGHT0, GL_DIFFUSE, diffuse);
	glLightfv(GL_LIGHT0, GL_SPECULAR, specular);

	glLightfv(GL_LIGHT0, GL_SPOT_DIRECTION, direction);
	glLightf (GL_LIGHT0, GL_SPOT_CUTOFF, 30);

	glEnable(GL_LIGHT0);

	//glEnable(GL_LIGHTING);
}

void process_physics()
{
	static int time = glutGet(GLUT_ELAPSED_TIME);
	int elapsed = glutGet(GLUT_ELAPSED_TIME) - time;

	NewtonUpdate(w.world().id(), elapsed / 1000.0f);
	
	time = glutGet(GLUT_ELAPSED_TIME);
}

//Size of shadow map
const int shadowMapSize=512;

//Textures
GLuint shadowMapTexture;

void draw_everything()
{
	process_active_keys();
	process_physics();

	Vector position = character->getLocation();
	position[1] += 0.8f;
	camera->setPosition(position);

	state state;
	state.camera = camera;

	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	camera->set(vertex(0, 0, 0));

	//First pass - from light's point of view
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	glMatrixMode(GL_PROJECTION);
	glPushMatrix();
	glLoadIdentity();
	gluPerspective(45.0f, 1.0f, 2.0f, 8.0f);

	glMatrixMode(GL_MODELVIEW);
	glPushMatrix();
	glLoadIdentity();
	camera->set(vertex(0, 2, 0));

	glPushAttrib(GL_VIEWPORT_BIT);
	glViewport(0, 0, shadowMapSize, shadowMapSize);

	//Draw back faces into the shadow map
	//glCullFace(GL_FRONT);

	//Disable color writes, and use flat shading for speed
	//glShadeModel(GL_FLAT);
	//glColorMask(0, 0, 0, 0);

	//w.draw(state);

	//Read the depth buffer into the shadow map texture
	glBindTexture(GL_TEXTURE_2D, shadowMapTexture);
	glCopyTexSubImage2D(GL_TEXTURE_2D, 0, 0, 0, 0, 0, shadowMapSize, shadowMapSize);

	glPopAttrib();

	glMatrixMode(GL_PROJECTION);
	glPopMatrix();

	glMatrixMode(GL_MODELVIEW);
	glPopMatrix();
w.draw(state);
	//2nd pass - Draw from camera's point of view
/*
	glClear(GL_DEPTH_BUFFER_BIT);

	//Use dim light to represent shadowed areas
	glLightfv(GL_LIGHT1, GL_POSITION, VECTOR4D(lightPosition));
	glLightfv(GL_LIGHT1, GL_AMBIENT, white*0.2f);
	glLightfv(GL_LIGHT1, GL_DIFFUSE, white*0.2f);
	glLightfv(GL_LIGHT1, GL_SPECULAR, black);
	glEnable(GL_LIGHT1);
	glEnable(GL_LIGHTING);

	DrawScene(angle);
	
	//3rd pass
	//Draw with bright light
	glLightfv(GL_LIGHT1, GL_DIFFUSE, white);
	glLightfv(GL_LIGHT1, GL_SPECULAR, white);

	//Calculate texture matrix for projection
	//This matrix takes us from eye space to the light's clip space
	//It is postmultiplied by the inverse of the current view matrix when specifying texgen
	static MATRIX4X4 biasMatrix(0.5f, 0.0f, 0.0f, 0.0f,
								0.0f, 0.5f, 0.0f, 0.0f,
								0.0f, 0.0f, 0.5f, 0.0f,
								0.5f, 0.5f, 0.5f, 1.0f);	//bias from [-1, 1] to [0, 1]
	MATRIX4X4 textureMatrix=biasMatrix*lightProjectionMatrix*lightViewMatrix;

	//Set up texture coordinate generation.
	glTexGeni(GL_S, GL_TEXTURE_GEN_MODE, GL_EYE_LINEAR);
	glTexGenfv(GL_S, GL_EYE_PLANE, textureMatrix.GetRow(0));
	glEnable(GL_TEXTURE_GEN_S);

	glTexGeni(GL_T, GL_TEXTURE_GEN_MODE, GL_EYE_LINEAR);
	glTexGenfv(GL_T, GL_EYE_PLANE, textureMatrix.GetRow(1));
	glEnable(GL_TEXTURE_GEN_T);

	glTexGeni(GL_R, GL_TEXTURE_GEN_MODE, GL_EYE_LINEAR);
	glTexGenfv(GL_R, GL_EYE_PLANE, textureMatrix.GetRow(2));
	glEnable(GL_TEXTURE_GEN_R);

	glTexGeni(GL_Q, GL_TEXTURE_GEN_MODE, GL_EYE_LINEAR);
	glTexGenfv(GL_Q, GL_EYE_PLANE, textureMatrix.GetRow(3));
	glEnable(GL_TEXTURE_GEN_Q);

	//Bind & enable shadow map texture
	glBindTexture(GL_TEXTURE_2D, shadowMapTexture);
	glEnable(GL_TEXTURE_2D);

	//Enable shadow comparison
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_COMPARE_MODE_ARB, GL_COMPARE_R_TO_TEXTURE);

	//Shadow comparison should be true (ie not in shadow) if r<=texture
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_COMPARE_FUNC_ARB, GL_LEQUAL);

	//Shadow comparison should generate an INTENSITY result
	glTexParameteri(GL_TEXTURE_2D, GL_DEPTH_TEXTURE_MODE_ARB, GL_INTENSITY);

	//Set alpha test to discard false comparisons
	glAlphaFunc(GL_GEQUAL, 0.99f);
	glEnable(GL_ALPHA_TEST);

	DrawScene(angle);

	//Disable textures and texgen
	glDisable(GL_TEXTURE_2D);

	glDisable(GL_TEXTURE_GEN_S);
	glDisable(GL_TEXTURE_GEN_T);
	glDisable(GL_TEXTURE_GEN_R);
	glDisable(GL_TEXTURE_GEN_Q);

	//Restore other states
	glDisable(GL_LIGHTING);
	glDisable(GL_ALPHA_TEST);
*/
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

	glGenTextures(1, &shadowMapTexture);
	glBindTexture(GL_TEXTURE_2D, shadowMapTexture);
	glTexImage2D(	GL_TEXTURE_2D, 0, GL_DEPTH_COMPONENT, shadowMapSize, shadowMapSize, 0,
					GL_DEPTH_COMPONENT, GL_UNSIGNED_BYTE, NULL);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP);

	glutMainLoop();
	return 0;
}
