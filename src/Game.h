/*
 * Game.h
 *
 * Author: Esa Varemo
 */

#ifndef GAME_H_
#define GAME_H_

#include "Ground.h"
#include "Cube.h"
#include "Entity.h"
#include "GameState.h"
#include "Stage.h"

class Game {
public:
	Game();
    void init();
	std::vector<Entity*>* getEntities();
    void setGameState(GameState state);
    GameState getGameState();
    Stage* getStage();
private:
    GameState gameState;
    Stage* stage;
	Cube *player;
	std::vector<Cube*> enemies;
};

#endif /* GAME_H_ */
