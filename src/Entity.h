#ifndef ENTITY_H
#define ENTITY_H

#include <vector>
#include "EntityFlags.h"

class Entity {

public:
	virtual void act();
	virtual void draw();

private:
	int x;
	int y;
	int z;

	std::vector<EntityFlags> flags;
};

#endif
