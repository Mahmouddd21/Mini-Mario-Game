//
// Created by abdul on 26/12/2022.
//

#ifndef UNTITLED_MAP_H
#define UNTITLED_MAP_H
#include "Champion.h"
#include "Cell.h"

class Map {
private:
    bool champType; //true= mario and false=Luigi
    Champion *champion;
    Cell ***board;
    int rows=10;
    int column=10;
public:
    ~Map();
    Map();
    void print_board();
    void randomize_board();
    void Move(char Direction,int x);
    void Helper();
    void Helper2();
    bool Get_champType();
    void Set_champType(bool b);


};


#endif //UNTITLED_MAP_H
