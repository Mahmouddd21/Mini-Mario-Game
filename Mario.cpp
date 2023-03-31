//
// Created by abdul on 26/12/2022.
//

#include <iostream>
using namespace std;
#include "../Game2/Mario.h"

Mario::Mario(int x, int y): Champion(x,y) {cout << "Mario Class is called" << endl;}

void Mario::useAbility() {
    this->setAbilityCount(this->getAbilityCount()-1);
    cout << "Mario Ability is called" << endl;
}
