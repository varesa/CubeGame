/*
 * Ground.h
 *
 * Author: Esa Varemo
 */

#ifndef GROUND_H_
#define GROUND_H_

#include "Entity.h"

class Ground: public Entity {
public:
	Ground();
	Ground(float x, float y, float width, float height);

    void draw();

    float getX();
    float getY();
    float getWidth();
    float getHeight();


private:
	// x,y and z inherited from Entity
	float width;
	float height;
};

#endif /* GROUND_H_ */
