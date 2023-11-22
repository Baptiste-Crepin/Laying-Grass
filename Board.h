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
    char **grid;

public:
    Board(int s);

    ~Board();

    void display() const;

    void setValue(int row, int col, char value) const;

    char getValue(int row, int col) const;

    int getSize() const;
};


#endif //LAYINGGRASS_BOARD_H