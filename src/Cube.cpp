/*
 * Cube.cpp
 *
 * Author: Esa Varemo
 */

#include <iostream>
#include <vector>
#include <math.h>

#include <GL/glut.h>

#include "Cube.h"
#include "Main.h"
#include "Game.h"
#include "Ground.h"
#include "Entity.h"
#include "utils.h"

#define PLAYER_MAXSPEED 80
#define PLAYER_ACCEL 15
#define PLAYER_DECEL 20

#define ENEMY_MAXSPEED 60
#define ENEMY_ACCEL 10
#define ENEMY_DECEL 10

#define GRAV_ACCEL 9

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
    vx = 0;
    vy = 0;
    wasGrounded = false;
}

void Cube::draw() {
    glTranslatef(x + 0.5 * size, y + 0.5 * size, -z - 0.5 * size - 40);
    glutWireCube(this->size);
    glTranslatef(-(x + 0.5 * size), -(y + 0.5 * size), z + 0.5 * size + 40);
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
            this->ytarget = 10;
        }

    } else {               // Or an enemy

    }

    this->applyPhysics(time);

}

void Cube::setPlayerControlled(bool pc) {
    this->playerControlled = pc;
}

void Cube::applyPhysics(long time) {
    float dTime = time;

    float origX = x;
    float origY = y;

    if(this->playerControlled) {
        if(this->xtarget < 0) {
            this->vx -= PLAYER_ACCEL * (dTime/100);
        } else if(this->xtarget > 0) {
            this->vx += PLAYER_ACCEL * (dTime/100);
        } else {
            int oldsign = sign(vx);
            this->vx -= sign(vx) * PLAYER_DECEL * (dTime/100);
            if(sign(vx) != oldsign) {
                vx=0;
            }
        }

        if(abs(vx) > PLAYER_MAXSPEED) {
            vx = sign(vx) * PLAYER_MAXSPEED;
        }

    } else {

    }


    if(ytarget > 1 && wasGrounded) {
        this->vy += 70;
    }


    wasGrounded = false;

    vy -= GRAV_ACCEL * (dTime/100);

    x += vx * (dTime/100);
    y += vy * (dTime/100);

    std::vector<Ground*> *ground = Main::getGame()->getStage()->getGround();

    unsigned int i;
    for(i = 0; i < ground->size(); i++) {
        Ground *g = ground->at(i);
        if( (g->getY() < y && y < g->getY()+g->getHeight()) || (g->getY() < y+size && y+size < g->getY()+g->getY()) ) {
            if(vx > 0) {
                if(origX+size < g->getX() && x+size > g->getX()) {
                    x = g->getX() - size - 0.1;
                    vx = 0;
                }
            } else {
                if(origX > g->getX()+g->getWidth() && x < g->getX()+g->getWidth()) {
                    x = g->getX() + g->getWidth() + 0.1;
                    vx = 0;
                }
            }
        }



        if( (g->getX() < x && x < g->getX() + g->getWidth()) || (g->getX() < x+size && x+size < g->getX() + g->getWidth())) {
            if(vy > 0) {
                if(origY+size < g->getY() && y+size > g->getY()) {
                    d("Hit up\n");
                    y = g->getY() - size - 0.1;
                    vy = 0;
                }
            } else {
                if(origY > g->getY() + g->getHeight() && y < g->getY() + g->getHeight()) {
                    d("Hit bottom\n");
                    y = g->getY() + g->getHeight() + 0.1;
                    vy = 0;
                    wasGrounded = true;
                }
            }
        }
    }

}
