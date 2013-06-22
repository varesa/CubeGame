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

private:
	//x, y and z inherited from Entity

    float vx;
    float vy;

	float size;
};

#endif /* CUBE_H_ */
