//
// Created by abdul on 26/12/2022.
//

#ifndef UNTITLED_THIEF_H
#define UNTITLED_THIEF_H
#include "Champion.h"
#include "Obstacle.h"

class Thief: public Obstacle {
public:
    Thief(int x, int y);
    void execute(Champion* c);
};


#endif //UNTITLED_THIEF_H
