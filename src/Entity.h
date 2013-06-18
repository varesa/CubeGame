#ifndef ENTITY_H
#define ENTITY_H

#include <vector>
#include "EntityFlags.h"

class Entity {

public:
	void act(long deltaT);
	void draw(long deltaT);

protected:
	float x;
	float y;
	float z;

	std::vector<EntityFlags> flags;
};

#endif
