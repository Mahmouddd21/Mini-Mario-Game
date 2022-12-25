#include <iostream>
using namespace std;
#include "Champion.cpp"
#include "Cell.cpp"
class Gem : public Cell{
private:
    int points;

public:

    Gem(){
        srand(time(0));
        this->points = rand() % (11 - 5) + 5;
        this->setCell('g');
    }

    virtual void execute(Champion c){}

    int Get_points(){
        return points;
    }
};


class Coin: public Gem{
public:
    Coin():Gem(){}
    void execute(Champion c){
        cout<<"Coin executed with points = "<<Get_points()<<endl;
        c.Set_gem_Score(c.Get_gem() + Get_points());
    }


};

class Potion:public Gem{
public:
    Potion():Gem(){}

    void execute(Champion c){
        cout<<"Potion executed with points = "<<Get_points()<<endl;
        if(c.Get_Health() + Get_points() > 100){
            c.Set_health(100);
        }else
            c.Set_health(c.Get_Health() + Get_points());
    }

};
