//
// Created by abdul on 26/12/2022.
//

#include "../Game2/Luigi.h"
#include <iostream>
using namespace std;

Luigi::Luigi(int x,int y): Champion(x,y) {
    cout << "Luigi Class is called" << endl;
}

void Luigi::useAbility() {
    this->setAbilityCount(this->getAbilityCount()-1);
    cout << "Luigi Ability is called" << endl;
}
