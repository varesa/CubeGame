/*
 * Game.cpp
 *
 * Author: Esa Varemo
 */

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

void Game::setGameState(GameState state) {
    this->gameState = state;
}

GameState Game::getGameState() {
    return this->gameState;
}

Stage* Game::getStage() {
    return stage;
}

void Game::init() {
	gameState = GameState::START;

    stage->initStage();
    //initGround();
}
