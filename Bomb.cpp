//
// Created by abdul on 26/12/2022.
//
#include <iostream>
#include <conio.h>

using namespace std;

#include "../Game2/Bomb.h"

Bomb::Bomb(int x, int y):Obstacle(x,y) {

}

void Bomb::execute(Champion* c) {
    if(c->getHealth() -  Get_dmg_amount() < 0){
        c->setHealth(0);
    }else
        c->setHealth(c->getHealth() - Get_dmg_amount());
    cout<<" bomb execute with dmg = "<<Get_dmg_amount()<<endl;
    getch();
}
