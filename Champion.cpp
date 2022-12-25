#include <iostream>
#include "Cell.cpp"

using namespace std;

class Champion : public Cell {

private:

    int health;
    int Gems_Score;
    int Champ_Score;
    int abilityCount;

public:
    Champion() : Cell('c',9,0){
        cout << "Constructor Champion() is called" << endl;
        this->health = 100;
        this->Gems_Score = 0;
        this->Champ_Score = 0;
        this->abilityCount = 2;
    }

    void print_champ_info() {

        if (health > 0) {
            cout << "Champ pos X: " << this->getY() << " Y: " << 10 - this->getX() - 1 << " , Champion Health: " << health
                 << " , Champion Score: " << Champ_Score << " , Champion Gems:"
                 << Gems_Score << "/40, " << "Remaining ability moves" << abilityCount <<  endl;
        } else {
            cout << "Champ pos X: " << this->getY() << " Y: " << 10 - this->getX() - 1 << " , Champion Health: 0 , Champion Score: "
                 << Champ_Score << " , Champion Gems:"
                 << Gems_Score << "/40"  << "Remaining ability moves" << abilityCount << endl;
        }
    }

    int Get_gem() {
        return Gems_Score;
    }

    void Set_gem_Score(int gem) {
        this->Gems_Score = gem;
    }

    int Get_Health() {
        return health;
    }

    void Set_health(int h) {
        this->health = h;
    }

    int Get_Champ_Score() {
        return Champ_Score;
    }

    void Set_Champ_Score(int c) {
        this->Champ_Score += c;
    }

    int getAbilityCount() const {
        return abilityCount;
    }

    void setAbilityCount(int abilityCount) {
        Champion::abilityCount = abilityCount;
    }

    virtual void useAbility(){cout << "ability x is used" << endl;}

};

class Mario : public Champion{
public:
    void useAbility(){cout << "Mario Ability is called" << endl;}
};

class Luigi : public Champion{
public:
    void useAbility(){cout << "Luigi Ability is called" << endl;}
};
