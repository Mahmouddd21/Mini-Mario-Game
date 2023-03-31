//
// Created by abdul on 26/12/2022.
//
using namespace std;
#include <iostream>
#include <conio.h>
#include "../Game2/Potion.h"

Potion::Potion(int x, int y): Gem(x,y) {
    //cout<<"Potion"<<endl;
}

void Potion::execute(Champion* c) {
    cout<<"Potion executed with points = "<<Get_points()<<endl;
    getch();
    c->Set_gem_Score(c->Get_gem()+1);
    if(c->getHealth() + Get_points() > 100){
        c->setHealth(100);
    }else
        c->setHealth(c->getHealth() + Get_points());
}
