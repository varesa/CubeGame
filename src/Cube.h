/*
 * Cube.h
 *
 * Author: Esa Varemo
 */

#ifndef CUBE_H_
#define CUBE_H_

#include "Entity.h"

class Cube : public Entity {
public:
	Cube(float x, float y, float z, float size);
	Cube();
	void draw();
	void act(bool* keys, long time);
    void setPlayerControlled(bool pc);

private:
	//x, y and z inherited from Entity

    float vx;
    float vy;

    float xtarget;
    float ytarget;

	float size;

    bool wasGrounded;
    bool playerControlled;

    void applyPhysics(long time);
};

#endif /* CUBE_H_ */
