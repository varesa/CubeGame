#include <fstream>
#include <iostream>
#include <exception>
#include <string>
#include <limits>

#include "Game.h"
#include "Ground.h"

Game::Game() {

}

std::vector<Entity*>* Game::getEntities() {
	std::vector<Entity*> *entities = new std::vector<Entity*>();

	entities->insert(entities->end(), ground->begin(), ground->end());

	return entities;
}

void Game::init() {
	initGround();
}

void Game::initGround() {
	std::ifstream *stageFile = new std::ifstream();
	stageFile->open("stage.txt");

	if(stageFile == nullptr ){//|| !stageFile->is_open()) {
		printf("Stage-file not found or could not open");
		throw std::exception();
	}

	std::string line;
	float *x, *y, *w, *h;
	while(std::getline(*stageFile, line)) {
		sscanf(line.c_str(), "%f %f %f %f", x, y, w, h);
		ground->push_back(new Ground(*x, *y ,*w, *h));
	}


}
