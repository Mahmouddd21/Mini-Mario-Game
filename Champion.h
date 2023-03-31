//
// Created by abdul on 26/12/2022.
//

#ifndef UNTITLED_CHAMPION_H
#define UNTITLED_CHAMPION_H
#include "Cell.h"

class Champion: public Cell{

private:

    int health;
    int Gems_Score;
    int Champ_Score;
    int abilityCount;

public:
    Champion(int x , int y);
    void print_champ_info();
    int Get_gem();
    void Set_gem_Score(int gem);
    int getHealth();
    void setHealth(int health);

    int Get_Champ_Score();
    void Set_Champ_Score(int c);
    int getAbilityCount();
    void setAbilityCount(int abilityCount);
    virtual void useAbility();


};


#endif //UNTITLED_CHAMPION_H
