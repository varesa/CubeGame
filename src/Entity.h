/*
 * Entity.h
 *
 * Author: Esa Varemo
 */

#ifndef ENTITY_H_
#define ENTITY_H_

#include <vector>

#include "EntityFlags.h"

class Entity {

public:
    virtual void act(bool* keys, long deltaT);
    virtual void draw();

protected:
	float x;
	float y;
	float z;

	std::vector<EntityFlags> flags;
};

#endif /* ENTITY_H_ */
