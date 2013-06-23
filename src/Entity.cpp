/*
 * Entity.cpp
 *
 * Author: Esa Varemo
 */

#include <stdio.h>

#include "Entity.h"

Entity::Entity() {
    x = 0;
    y = 0;
    z = 0;
}

void Entity::act(bool*keys, long deltaT) {
    //printf("How did we get here? Entity::act()\n");
    //fflush(stdout);
}

void Entity::draw() {
    printf("How did we get here? Entity::draw()\n");
    fflush(stdout);
}
