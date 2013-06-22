#include "Ground.h"
#include "Cube.h"
#include "Entity.h"
#include "GameState.h"
#include "Stage.h"

#ifndef GAME_H
#define GAME_H

class Game {
public:
	Game();
	void init();
	GameState gameState;
	std::vector<Entity*>* getEntities();
private:

    Stage* stage;
	Cube *player;
	std::vector<Cube*> enemies;
};

#endif
