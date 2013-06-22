#ifndef STAGE_H
#define STAGE_H

#include <fstream>
#include <vector>

#include "Ground.h"
#include "Entity.h"

class Stage
{
public:
    Stage();
    void initStage();
    std::vector<Entity*>* getEntities();
private:
    void initGround(std::ifstream* file);
    void initEnemySpawns(std::ifstream* file);
    void initPlayerSpawn(std::ifstream* file);

    std::vector<Ground*> *ground;
};

#endif // STAGE_H
