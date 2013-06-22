/*
 * Stage.cpp
 *
 * Author: Esa Varemo
 */

#include <fstream>
#include <string>
#include <iostream>
#include <stdio.h>

#include "Stage.h"

Stage::Stage()
{
    ground = new std::vector<Ground*>();
}

void Stage::initStage() {
    std::ifstream *stageFile = new std::ifstream();
    stageFile->open("stage.txt");

    if(stageFile == nullptr || !stageFile->is_open()) {
        printf("Stage-file not found or could not open");
        throw std::exception();
    }

    initGround(stageFile);
    initEnemySpawns(stageFile);
    initPlayerSpawn(stageFile);
}

void Stage::initGround(std::ifstream* file) {
    std::string line;
    float x, y, w, h;
    while(std::getline(*file, line)) {
        if(line.length() > 0 && line.at(0) == 'g') {
            printf("Found ground-line\n");
            sscanf(line.c_str(), "g%f %f %f %f", &x, &y, &w, &h);
            ground->push_back(new Ground(x, y , w, h));
        }
    }
}

std::vector<Entity*>* Stage::getEntities() {
    std::vector<Entity*> *entities = new std::vector<Entity*>();
    entities->insert(entities->end(), ground->begin(), ground->end());
    return entities;
}

void Stage::initEnemySpawns(std::ifstream* file) {
    std::string line;
    while(std::getline(*file, line)) {
        if(line.length() > 0 && line.at(0) == 'e') {
            printf("Found enemy-line\n");
        }
    }
}

void Stage::initPlayerSpawn(std::ifstream* file) {
    std::string line;
    while(std::getline(*file, line)) {
        if(line.length() > 0 && line.at(0) == 'p') {
            printf("Found player-line\n");
        }
    }
}
