#include <iostream>
using namespace std;

class Cell{
private:
    char cell;
    int x;
    int y;
public:
    Cell(char cell = '.', int x = 0, int y = 0){
        this->cell = cell;
        this->x = x;
        this->y = y;
    }

    char getCell() const {
        return cell;
    }

    void setCell(char cell) {
        Cell::cell = cell;
    }

    int getX() const {
        return x;
    }

    void setX(int x) {
        Cell::x = x;
    }

    int getY() const {
        return y;
    }

    void setY(int y) {
        Cell::y = y;
    }

    void operator= (char c){
        cell = c;
    }

    bool operator== (Cell c){
        return (c.cell == this->cell) && (c.y == this->y) && (c.x == this->x);
    }

   friend ostream& operator<< (ostream &os, const Cell & c);

};

ostream& operator<< (ostream &os, const Cell cell){
    os << cell.getCell();
    return os;
}