//
// Created by abdul on 26/12/2022.
//
#include <iostream>
#include <cstdlib>
#include <ctime>
#include "../Game2/Obstacle.h"
using namespace std;

Obstacle::Obstacle(int x, int y) :Cell('o',x,y){
    srand(time(0));
    this-> dmg_amount = 1+(rand() % 5);
//        this->setCell('o');
}

void Obstacle::execute(Champion* c) {

}

int Obstacle::Get_dmg_amount() {
    return this->dmg_amount;
}
