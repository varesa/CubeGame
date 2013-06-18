/*
 * Cube.h
 *
 *  Created on: Jan 31, 2013
 *      Author: esa
 */

#include "Entity.h"

#ifndef CUBE_H_
#define CUBE_H_

class Cube : public Entity {
public:
	Cube(float x, float y, float z, float size);
	Cube();
	void draw();
	void act(bool* keys, long time);

private:
	//x, y and z inherited from Entity

	float vx = 0;
	float vy = 0;

	float size;
};

#endif /* CUBE_H_ */
