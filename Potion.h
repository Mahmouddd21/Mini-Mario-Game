//
// Created by abdul on 26/12/2022.
//

#ifndef UNTITLED_POTION_H
#define UNTITLED_POTION_H
#include "Champion.h"
#include "Gem.h"

class Potion: public Gem{
public:
    Potion(int x,int y);
    void execute(Champion* c);
};


#endif //UNTITLED_POTION_H
