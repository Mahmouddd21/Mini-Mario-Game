//
// Created by abdul on 26/12/2022.
//

#ifndef UNTITLED_GEM_H
#define UNTITLED_GEM_H
#include "Champion.h"

class Gem :public Cell{
private:
    int points;
public:
    Gem(int x,int y);
    virtual void execute(Champion* c);
    int Get_points();
};


#endif //UNTITLED_GEM_H
