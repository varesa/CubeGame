#include <fstream>
#include <iostream>
#include <exception>
#include <string>

#include "Game.h"
#include "Ground.h"
#include "Stage.h"

Game::Game() {
    stage = new Stage();
}

std::vector<Entity*>* Game::getEntities() {
    //std::vector<Entity*> *entities = new std::vector<Entity*>();
    //entities->insert(entities->end(), ground->begin(), ground->end());
    //return entities;
    return stage->getEntities();
}

void Game::init() {
	gameState = GameState::START;

    stage->initStage();
    //initGround();
}
