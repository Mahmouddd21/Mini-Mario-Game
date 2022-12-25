#include <iostream>
#include "random"
#include "math.h"
#include "stdlib.h"
#import "Champion.cpp"
#import "Cell.cpp"
#import "Gem.cpp"
#import "Obstacle.cpp"
#include<conio.h>

using namespace std;

class Map {

private:


    Champion * champion;
    Cell ** board;


public:

    ~Map() {
        delete (board);
        delete (champion);
    }

    Map() {

        cout << "Constructor Map() is called" << endl;
        board = new Cell *[10];
        for (int i = 0; i < 10; i++) {
            board[i] = new Cell[10];
        }
        this->champion = new Champion();
        randomize_board();
        Helper2();
    }

    void print_board() {

        for (int i = 0; i < 10; ++i) {
            for (int j = 0; j < 10; ++j) {
                cout << &board[i][j] << " " << endl;
            }
            cout << endl;
        }
        cout << "print_board() called" << endl;
        champion->print_champ_info();
    }

    void randomize_board() {
        srand(time(0));
        for (int i = 0; i < 10; ++i) {
            for (int j = 0; j < 10; ++j) {
                board[i][j] = '.';
            }
        }
        //champ location
        board[champion->getX()][champion->getY()] = champion->getCell();

//randomly allocated gems
        int i = 0;
        while (i < 40) {
            int x = rand() % 10;
            int y = rand() % 10;
            if (board[x][y].getCell() == '.') {
                board[x][y] = new Gem *();
                i++;
            }
        }


//randomly allocated obstacles
        int j = 0;
        while (j < 20) {
            int x = rand() % 10;
            int y = rand() % 10;
            if (board[x][y] == '.') {
                board[x][y] = obstacle;
                j++;
            }
        }
        cout << "randomize_board() called" << endl;
        print_board();
    }

    void Move(char Direction) {
        int pointX = champion->getX();
        int pointY = champion->getY();

        board[pointX][pointY] = '.';

        if (Direction == '8' || Direction == 72) {   //move up
            pointX -= 1;
            pointY;

        } else if (Direction == '5' || Direction == 80) {  //move down
            pointX += 1;
            pointY;
        } else if (Direction == '6' || Direction == 77) {  //move right
            pointX;
            pointY += 1;
        } else if (Direction == '4' || Direction == 75) {  //move left
            pointX;
            pointY -= 1;
        }
        if (pointX > 9) {
            pointX--;
        } else if (pointY > 9) {
            pointY--;
        } else if (pointX < 0) {
            pointX++;
        } else if (pointY < 0) {
            pointY++;
        }
        if (champion->Get_gem() < 40) {
            if (board[pointX][pointY].getCell() == 'g') {
                //should learn how to execute the method of Gem class
            } else if (board[pointX][pointY] == 'o') {
                //should learn how to execute the method of Gem class
            }
        } else {
            cout << "You win!" << endl;
            abort();
        }champion->setX(pointX);
        champion->setY(pointY);
        board[pointX][pointY] = *champion;
    }

    void Helper() {  // Direction
        while (true) {
            if (champion->Get_Health() > 0) {
                char x;
                cin >> x;
                x = getch();
                char move;
                cout << "Enter Direction " << endl;
                move = getch();
                if (x == 'x' || x == 'X'){
                    if (champion->getAbilityCount() > 2){
                        champion->setAbilityCount(champion->getAbilityCount() - 1);
                        champion->useAbility();
                        Move(move);
                        Move(move);
                    }
                    else{
                        cout << "Cannot use abiltiy any more!!" << endl;
                    }
                }
                Move(move || x);
                system("CLS");
                print_board();
            } else {
                cout << "Game Over!" << endl;
                abort();
            }
        }

    }

    void Helper2() {  //generate another board
        while (true) {
            cout << "would you like generate another random board(for yes 1 to start 2) ";
            int x;
            cin >> x;
            if (x == 1) {
                system("CLS");
                randomize_board();

            } else if (x == 2) {
                cout << "Game Started" << endl;
                Helper();
            }
        }
    }


};