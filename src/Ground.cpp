/*
 * Ground.cpp
 *
 * Author: Esa Varemo
 */


#include <iostream>

#include <GL/gl.h>
#include <GL/glu.h>
#include <GL/glut.h>

#include "Ground.h"


Ground::Ground(float x, float y, float w, float h) {
	this->x = x;
	this->y = y;
	this->width = w;
	this->height = h;

    if(width < 0) {
        x -= width;
        width = -width;
    }

    if(height < 0) {
        y -= height;
        y = -y;
    }
}

Ground::Ground() {

}

void Ground::draw(long deltaT) {
	glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
	glBegin(GL_QUADS);
		glVertex3f(x+width, y+height, 0);
		glVertex3f(x, y+height, 0);
		glVertex3f(x, y, 0);
		glVertex3f(x+width, y, 0);
		glVertex3f(x+width, y+height, 0);
	glEnd();

	glBegin(GL_QUADS);
		glVertex3f(x+width, y+height, -128);
		glVertex3f(x+width, y+height, 0);
		glVertex3f(x+width, y, 0);
		glVertex3f(x+width, y, -128);
		glVertex3f(x+width, y+height, -128);
	glEnd();

	glBegin(GL_QUADS);
		glVertex3f(x, y+height, -128);
		glVertex3f(x, y+height, 0);
		glVertex3f(x, y, 0);
		glVertex3f(x, y, -128);
		glVertex3f(x, y+height, -128);
	glEnd();

	glBegin(GL_QUADS);
		glVertex3f(x+width, y+height, -128);
		glVertex3f(x, y+height, -128);
		glVertex3f(x, y, -128);
		glVertex3f(x+width, y, -128);
		glVertex3f(x+width, y+height, -128);
	glEnd();
}

float Ground::getX() {
    return x;
}

float Ground::getY(){
    return y;
}

float Ground::getWodth(){
    return width;
}

float Ground::getHeight(){
    return height;
}
