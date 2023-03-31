//
// Created by abdul on 26/12/2022.
//
#include <iostream>
#include <conio.h>

using namespace std;
#include "../Game2/Thief.h"

Thief::Thief(int x, int y):Obstacle(x,y) {

}

void Thief::execute(Champion* c) {
    if(c->Get_gem() - Get_dmg_amount() < 0){
        c->Set_gem_Score(0);
    }else
        c->Set_gem_Score(c->Get_gem()- Get_dmg_amount());

    cout<<" Thief executed with dmg = "<<Get_dmg_amount()<<endl;
    getch();
}
