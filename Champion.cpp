//
// Created by abdul on 26/12/2022.
//
#include <iostream>
#include "Champion.h"
using namespace std;

Champion::Champion(int x, int y):Cell('c',x,y) {
    cout << "Constructor Champion() is called" << endl;
    this->health = 100;
    this->Gems_Score = 0;
    this->Champ_Score = 0;
    this->setX(9);
    this->setY(0);
    this->abilityCount = 2;
}

void Champion::print_champ_info() {

    if (health > 0) {
        cout << "Champ pos X: " << this->getY() << " Y: " << 10 - this->getX() - 1 << " , Champion Health: " << health
             << " , Champion Score: " << Gems_Score
             << ", " << "Remaining ability moves: " << abilityCount <<  endl;
    } else {
        cout << "Champ pos X: " << this->getY() << " Y: " << 10 - this->getX() - 1 << " , Champion Health: 0 , Champion Score: "
             << Gems_Score
             <<  ""  << "Remaining ability moves: " << abilityCount << endl;
    }


}

int Champion::getHealth() {return health;}

void Champion::setHealth(int health) {Champion::health = health;}

int Champion::Get_gem() {
    return Gems_Score;
}

void Champion::Set_gem_Score(int gem) {
    Gems_Score = gem;
}

int Champion::Get_Champ_Score() {
    return Champ_Score;
}

void Champion::Set_Champ_Score(int c) {
    this->Champ_Score += c;
}

int Champion::getAbilityCount() {
    return abilityCount;
}

void Champion::setAbilityCount(int abilityCount) {
    Champion::abilityCount = abilityCount;

}

 void Champion::useAbility() {

    cout << "ability x is used" << endl;
}
