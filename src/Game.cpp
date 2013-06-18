#include "Game.h"

Game::Game() {

}

std::vector<Entity>* Game::getEntities() {
	std::vector<Entity> *entities = new std::vector<Entity>();

	entities->insert(entities->end(), ground->begin(), ground->end());

	return entities;
}
