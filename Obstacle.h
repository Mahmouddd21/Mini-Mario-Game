    //
// Created by abdul on 26/12/2022.
//

#ifndef UNTITLED_OBSTACLE_H
#define UNTITLED_OBSTACLE_H
#include "Champion.h"

class Obstacle: public Cell{
private:
    int dmg_amount;
public:
    Obstacle(int x,int y);
    virtual void execute(Champion* c);
    int Get_dmg_amount();

};


#endif //UNTITLED_OBSTACLE_H
