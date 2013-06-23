/*
 * Stage.h
 *
 * Author: Esa Varemo
 */

#ifndef STAGE_H_
#define STAGE_H_

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
    std::vector<Entity*> *otherEntities;
};

#endif /* STAGE_H_ */
