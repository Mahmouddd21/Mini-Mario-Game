//
// Created by abdul on 26/12/2022.
//
using namespace std;
#include <iostream>
#include <conio.h>
#include "../Game2/Coin.h"

Coin::Coin(int x, int y):Gem(x,y) {
//cout<<"coin"<<endl;
}

void Coin::execute(Champion* c) {

    c->Set_gem_Score(c->Get_gem() + this->Get_points());
    cout<<"Coin executed with points = "<<Get_points()<<endl;
    getch();
}
