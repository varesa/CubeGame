/*
 * Cube.cpp
 *
 * Author: Esa Varemo
 */

#include <iostream>
#include <math.h>

#include <GL/glut.h>

#include "Cube.h"
#include "utils.h"

#define PLAYER_MAXSPEED 10
#define PLAYER_ACCEL 1
#define PLAYER_DECEL 1

#define ENEMY_MAXSPEED 9
#define ENEMY_ACCEL 1
#define ENEMY_DECEL 1

#define GRAV_ACCEL 1

Cube::Cube(float x, float y, float z, float size) {
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
    if(playerControlled) { // A player

        this->xtarget = 0;
        this->ytarget = 0;

        if(keys[GLUT_KEY_LEFT]) {
            this->xtarget = -1;
        }

        if(keys[GLUT_KEY_RIGHT]) {
            this->xtarget = 1;
        }

        if(keys[GLUT_KEY_LEFT] && keys[GLUT_KEY_RIGHT]) {
            this->xtarget = 0;
        }

        if(keys[GLUT_KEY_UP]) {
            this->ytarget = 1;
        }

    } else {               // Or an enemy

    }

    this->applyPhysics(time);

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

void Cube::setPlayerControlled(bool pc) {
    this->playerControlled = pc;
}

void Cube::applyPhysics(long time) {
    if(this->playerControlled) {
        if(this->xtarget < 0) {
            this->vx -= PLAYER_ACCEL;
        } else if(this->xtarget > 0) {
            this->vx += PLAYER_ACCEL;
        } else {
            //this->vx
            printf("%l",time);
        }

        if(abs(vx) > PLAYER_MAXSPEED) {
            vx = sign(vx) * PLAYER_MAXSPEED;
        }

    } else {

    }


}
