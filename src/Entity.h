#ifndef ENTITY_H
#define ENTITY_H

#include <vector>
#include "EntityFlags.h"

class Entity {

public:
	void act();
	void draw();

private:
	int x;
	int y;
	int z;

	std::vector<EntityFlags> flags;
};

#endif
