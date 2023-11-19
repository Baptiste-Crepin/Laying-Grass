//
// Created by Baptiste Crepin on 11/11/2023.
//

#ifndef LAYINGGRASS_BOARD_H
#define LAYINGGRASS_BOARD_H

#include <vector>
#include <iostream>

class Board {
private:
    int size;
    char** grid;

public:
    Board(int s);
    ~Board();
    void display();
    void setValue(int row, int col, char value);
    char getValue(int row, int col);
};


#endif //LAYINGGRASS_BOARD_H