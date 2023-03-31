//
// Created by abdul on 26/12/2022.
//

#ifndef UNTITLED_COIN_H
#define UNTITLED_COIN_H
#include "Champion.h"
#include "Gem.h"

class Coin: public Gem{
public:
    Coin(int x, int y);
    void execute(Champion* c);

};


#endif //UNTITLED_COIN_H
