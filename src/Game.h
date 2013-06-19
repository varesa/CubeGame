#include "Ground.h"
#include "Cube.h"
#include "Entity.h"
#include "GameState.h"

#ifndef GAME_H
#define GAME_H

class Game {
public:
	Game();
	void init();
	GameState gameState;
	std::vector<Entity*>* getEntities();
private:
	void initGround();
	std::vector<Ground*> *ground;
	Cube *player;
	std::vector<Cube*> enemies;
};

#endif
