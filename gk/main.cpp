#include <windows.h>
#include <GL/gl.h>
#include <GL/glu.h>
#include <GL/glut.h>
#include <stdio.h>

int angle;

void displayFrame(void)
{
	glClearColor(0,0,0,0);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	glMatrixMode(GL_MODELVIEW); //Prze��czenie w tryb macierzy widoku modelu
	glLoadIdentity(); //Za�adowanie macierzy jednostkowej
	gluLookAt(7,7,7,0,0,0,0,1,0);

	glRotated(angle,0,1,0);
	glColor3b(20,40,60);
	glutSolidTorus(1,3,40,40);

	glutSwapBuffers();
}

void nextFrame(int value)
{
	angle=(angle+5)%360;
	glutTimerFunc(41,nextFrame,1);
	glutPostRedisplay();
}

int main(int argc, char* argv[])
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
	glutInitWindowSize(400,400);
	glutInitWindowPosition(0,0);
	glutCreateWindow("Program OpenGL");

	glutDisplayFunc(displayFrame);
	
	glMatrixMode(GL_PROJECTION); //Prze��czenie w tryb macierzy rzutowania
	glLoadIdentity(); //Za�adowanie macierzy jednostkowej
	gluPerspective(55,1,1,50);

	glEnable(GL_LIGHTING);
	glEnable(GL_LIGHT0);
	glEnable(GL_DEPTH_TEST);
	glEnable(GL_COLOR_MATERIAL);

	//glShadeModel(GL_SMOOTH);

	glutTimerFunc(41,nextFrame,1);
	glutMainLoop();
	return 0;
}