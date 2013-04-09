/*
 * Cube.cpp
 *
 *  Created on: Jan 31, 2013
 *      Author: esa
 */

#include <iostream>

#include <GL/glut.h>

#include "Cube.h"

Cube::Cube(int x, int y, int z, int size) {
	this->x = x;
	this->y = y;
	this->z = z;
	this->size = size;
}

Cube::Cube() {
	x = 0;
	y = 0;
	z = 0;
	size = 10;
}

void Cube::draw() {
	glTranslatef(x, y, z);
	glutWireCube(this->size);
	glTranslatef(-x, -y, -z);
}

void Cube::act(bool* keys, long time) {
	/*if(keys[GLUT_KEY_UP]) {
		z -= time*0.1;
	}

	if(keys[GLUT_KEY_DOWN]) {
		z += time*0.1;
	}

	if(keys[GLUT_KEY_LEFT]) {
		x -= time*0.1;
	}

	if(keys[GLUT_KEY_RIGHT]) {
		x += time*0.1;
	}*/
}

