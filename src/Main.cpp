/*
 * Main.cpp
 *
 *  Created on: Feb 2, 2013
 *      Author: esa
 */

#include <GL/gl.h>
#include <GL/glu.h>
#include <GL/glut.h>
#include <iostream>

void initGLUT(int argc, char **argv) {
	std::cout << "Initializing GLUT\n";
	glutInit(&argc, argv);

	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA | GLUT_DEPTH);
	glutInitWindowPosition(-1, -1);
	glutInitWindowSize(800,600);

	glutCreateWindow("The cube game");
}

void changeSize(int w, int h) {

	// Prevent a divide by zero, when window is too short
	// (you cant make a window of zero width).
	if (h == 0)
		h = 1;

	float ratio =  w * 1.0 / h;

	// Use the Projection Matrix
	glMatrixMode(GL_PROJECTION);

	// Reset Matrix
	glLoadIdentity();

	// Set the viewport to be the entire window
	glViewport(0, 0, w, h);

	// Set the correct perspective.
	gluPerspective(45,ratio,1,1000);

	// Get Back to the Modelview
	glMatrixMode(GL_MODELVIEW);
}

bool* spKeys = new bool[256];

void renderScene() {
	glClear(GL_DEPTH_BUFFER_BIT | GL_COLOR_BUFFER_BIT);
	glLoadIdentity();

	glutSwapBuffers();
}

void specialPressed(int key, int x, int y) {
	spKeys[key] = true;
}

void specialUp(int key, int x, int y) {
	spKeys[key] = false;
}

int main(int argc, char **argv) {
	std::cout << "Starting up\n";
	initGLUT(argc, argv);

	glutReshapeFunc(changeSize);

	glutSpecialFunc(specialPressed);
	glutSpecialUpFunc(specialUp);

	glutDisplayFunc(renderScene);
	glutIdleFunc(renderScene);

	std::cout << "Going to main loop\n";

	glutMainLoop();
}
