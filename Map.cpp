//
// Created by abdul on 26/12/2022.
//
#include <iostream>
#include <conio.h>

using namespace std;
#include "../Game2/Map.h"
#include "Coin.h"
#include "Potion.h"
#include "Bomb.h"
#include "Thief.h"
#include "Mario.h"
#include "Luigi.h"

Map::~Map() {
    delete (board);
    delete (champion);
}
bool Map::Get_champType() {
    return champType;
}
void Map::Set_champType(bool b) {
    this->champType = b;
}

Map::Map() {
    cout << "Constructor Map() is called" << endl;
    board = new Cell**[rows]; //t8yer
    for (int i = 0; i < rows; i++) {
        board[i] = new Cell*[column];  //t8yer
    }

    Helper2();


}

void Map::print_board() {
    for (int i = 0; i < 10; ++i) {
        for (int j = 0; j < 10; j++) {
            cout << board[i][j]->getCell() << " " ; //t8yer
        }
        cout << endl;
    }
    cout << "print_board() called" << endl;
    champion->print_champ_info();

}

void Map::randomize_board() {
    srand(time(0));

    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            board[i][j] = new Cell('.',i,j); //t8yer
        }
    }

    //champ location
    // board[champion->getX()][champion->getY()] = *new Champion(100 , champion->getX(),champion->getY());
    board[champion->getX()][champion->getY()]->setCell(champion->getCell()); //t8yer



//randomly allocated Coin
    int i = 0;
    while (i < 20) {
        int x = rand() % 10;
        int y = rand() % 10;
        if (board[x][y]->getCell() == '.') {
            board[x][y] = new Coin(x,y); //t8yer
            i++;
        }
    }
//randomly allocated Potion
    i = 0;
    while (i < 20) {
        int x = rand() % 10;
        int y = rand() % 10;
        if (board[x][y]->getCell() == '.') {
            board[x][y] = new Potion(x,y); //t8yer
            i++;
        }
    }


//randomly allocated Bomb
    int j = 0;
    while (j < 10) {
        int x = rand() % 10;
        int y = rand() % 10;
        if (board[x][y]->getCell() == '.') {
            board[x][y] = new Bomb(x,y); //t8yer
            j++;
        }
    }
//randomly allocated Thief
    j = 0;
    while (j < 10) {
        int x = rand() % 10;
        int y = rand() % 10;
        if (board[x][y]->getCell() == '.') {
            board[x][y] = new Thief(x,y);
            j++;
        }
    }



    cout << "randomize_board() called" << endl;
    print_board();

}

void Map::Move(char Direction,int x) {
    int pointX = champion->getX();
    int pointY = champion->getY();

    board[pointX][pointY]->setCell('.');

    if (Direction == '8' || Direction == 72) {   //move up
        pointX -= x;
        pointY;

    } else if (Direction == '5' || Direction == 80) {  //move down
        pointX +=  x;
        pointY;
    } else if (Direction == '6' || Direction == 77) {  //move right
        pointX;
        pointY += x;
    } else if (Direction == '4' || Direction == 75) {  //move left
        pointX;
        pointY -= x;
    }
    if (pointX > 9) {
        pointX -= x;
    } else if (pointY > 9) {
        pointY-=x;
    } else if (pointX < 0) {
        pointX+=x;
    } else if (pointY < 0) {
        pointY+=x;
    }


        if (board[pointX][pointY]->getCell() == 'g') {
          Gem *g = static_cast<Gem*>(board[pointX][pointY]) ;
          g->execute(champion);
        } else if (board[pointX][pointY]->getCell() == 'o') {
            Obstacle *o = static_cast<Obstacle*>((board[pointX][pointY])) ;
            o->execute(champion);//t8yer
        }

    champion->setX(pointX);
    champion->setY(pointY);
    board[pointX][pointY]->setCell(champion->getCell()) ;
}

void Map::Helper() {
    while (true) {
        if (champion->getHealth() > 0) {
            cout << "Enter Direction or click x for ability " << endl;

            char move;
            move = getch();
            if (move == 'x' || move == 'X') {
                if (champion->getAbilityCount() >0) {


                    champion->useAbility();

                    if (Get_champType() == true) {
                        cout << "Enter Direction" << endl;
                        move = getch();
                        Move(move, 2);
                        system("CLS");
                        print_board();
                    } else {
                        char c;
                        cout << "Enter Direction " << endl;
                         c=getch();
                        if (c == '8' || c == 72) {    //move
                            for (int i = champion->getX() - 1; i >= 0; i--) {
                                if (board[i][champion->getY()]->getCell() == 'o') {
                                    board[i][champion->getY()] = new Cell('.', i, champion->getY());
                                }
                            }
                        } else if (c == '5' || c == 80) {   //down
                            for (int i = champion->getX() + 1; i <= 9; i++) {
                                if (board[i][champion->getY()]->getCell() == 'o') {
                                    board[i][champion->getY()] = new Cell('.', i, champion->getY());
                                }
                            }
                        } else if (c == '6' || c == 77) {  //right
                            for (int i = champion->getY() + 1; i <= 9; i++) {
                                if (board[champion->getX()][i]->getCell() == 'o') {
                                    board[champion->getX()][i] = new Cell('.', champion->getX(), i);
                                }
                            }
                        } else if (c == '4' || c == 75) { //left

                            for (int i = champion->getY() - 1; i >= 9; i--) {
                                if (board[champion->getX()][i]->getCell() == 'o') {
                                    board[champion->getX()][i] = new Cell('.', champion->getX(), i);
                                }
                            }
                        }
                        system("CLS");
                        print_board();
                    }


                } else {
                    cout << "Cannot use ability any more!!" << endl;
                }
            } else {

                Move(move, 1);
                system("CLS"); //haya
                print_board();
            }
        } else {
            cout << "Game Over!" << endl;
            abort();
        }
    }
}
    void Map::Helper2() {

     cout<<"Welcome to level 2"<<endl;
while(true){
    char champ;
    cout << "Choose Mario Champion (M) or Luigi (L) ";
    cin >> champ;
    if (champ == 'M') {
        Set_champType(true);
        this->champion = new Mario(0,9);
        break;

    } else if( champ == 'L'){
        Set_champType(false);
        this->champion = new Luigi(0, 9);
        break;

    }else
        cout<<"Error"<<endl;
}



        while (true) {

            randomize_board();
            cout << "would you like generate another random board(for yes 2 to start 1) ";
            int x;
            cin >> x;
            if (x == 2) {

                randomize_board();
                system("CLS");

            } else if (x == 1) {
                cout << "Game Started" << endl;
                Helper();
            }
        }
    }


