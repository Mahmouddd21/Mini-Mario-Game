#include <iostream>
using namespace std;
#include "Champion.cpp";
#include "Cell.cpp"

class Obstacle : public Cell{//needs adjustment in Gems
private:
    int dmg_amount;
public:
    Obstacle() : Cell('o'){
        srand(time(0));
        this-> dmg_amount = 1+(rand() % 5);
    }
    virtual void execute(Champion c);

    int Get_dmg_amount(){
        return this->dmg_amount;
    }
};


class Bomb: public Obstacle{

public:
    void execute(Champion c){

        if(c.Get_Health() -  Get_dmg_amount() < 0){
            c.Set_health(0);
        }else
            c.Set_health(c.Get_Health() - Get_dmg_amount());
        cout<<" bomb excuted with dmg = "<<Get_dmg_amount()<<endl;
    }


};


class Thief: public Obstacle{
public:
    void execute(Champion c){
        if(c.Get_gem() - Get_dmg_amount() < 0){
            c.Set_gem_Score(0);
        }else
            c.Set_gem_Score(c.Get_gem()- Get_dmg_amount());

        cout<<" Thief excuted with dmg = "<<Get_dmg_amount()<<endl;

    }


};