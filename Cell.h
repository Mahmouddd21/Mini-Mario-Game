//
// Created by abdul on 26/12/2022.
//

#ifndef UNTITLED_CELL_H
#define UNTITLED_CELL_H


class Cell {
private:
    char cell;
    int x;
    int y;
public:

    Cell(char cell = '.', int x = 0, int y = 0);
    char getCell() ;
    void setCell(char cell);
    int getX() ;
    void setX(int x);
    int getY() ;
    void setY(int y);

};


#endif //UNTITLED_CELL_H
