//
// Created by abdul on 26/12/2022.
//

#ifndef UNTITLED_BOMB_H
#define UNTITLED_BOMB_H
#include "Champion.h"
#include "Obstacle.h"

class Bomb: public Obstacle{
public:
    Bomb(int x,int y);
    void execute(Champion* c);

};


#endif //UNTITLED_BOMB_H
