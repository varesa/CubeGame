#include "Ground.h"
#include "Cube.h"
#include "GameState.h"

#ifndef GAME_H
#define GAME_H

class Game {
public:
	Game();
	GameState gameState;

private:
	std::vector<Ground> ground;
	Cube player;
	std::vector<Cube> enemies;
};

#endif
