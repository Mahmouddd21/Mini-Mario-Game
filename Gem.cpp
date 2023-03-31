//
// Created by abdul on 26/12/2022.
//

#include <ctime>
#include <cstdlib>
#include "../Game2/Gem.h"

Gem::Gem(int x, int y): Cell('g',x,y) {
    srand(time(0));
    this->points = rand()%(11-5)+5;
}

void Gem::execute(Champion* c) {

}

int Gem::Get_points() {
    return points;
}
