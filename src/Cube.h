/*
 * Cube.h
 *
 *  Created on: Jan 31, 2013
 *      Author: esa
 */

#ifndef CUBE_H_
#define CUBE_H_

class Cube {
public:
	Cube(int x, int y, int z, int size);
	Cube();
	void draw();
	void act(bool* keys, long time);

private:
	int x;
	int y;
	int z;

	int vx;
	int vy;

	int size;
};

#endif /* CUBE_H_ */
