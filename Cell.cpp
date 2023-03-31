//
// Created by abdul on 26/12/2022.
//

#include "../Game2/Cell.h"


Cell::Cell(char cell , int x, int y) {
    this->cell = cell;
    this->x = x;
    this->y = y;
}

char Cell::getCell()  {
    return cell;
}

void Cell::setCell(char cell) {
    this->cell = cell;
}

int Cell::getX()  {
    return x;
}

void Cell::setX(int x) {
    this->x = x;
}

int Cell::getY()  {
    return y;
}

void Cell::setY(int y) {
    this->y = y;
}
