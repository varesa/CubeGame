/*
 * Ground.h
 *
 *  Created on: Jun 19, 2013
 *      Author: esa
 */

#ifndef GROUND_H_
#define GROUND_H_

#include "Entity.h"

class Ground: public Entity {
public:
	Ground();

private:
	// x,y and z inherited from Entity
	int width;
	int height;
};

#endif /* GROUND_H_ */
