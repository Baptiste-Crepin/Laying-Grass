//
// Created by Baptiste Crepin on 11/11/2023.
//

#ifndef LAYINGGRASS_BOARD_H
#define LAYINGGRASS_BOARD_H

#include <vector>
#include <iostream>
#include "Cells/Cell.h"

class Board {
private:
    int size;
    Cell **grid;

public:
    Board(int s);

    ~Board();

    void display() const;

    void setValue(int row, int col, Cell value) const;

    Cell getValue(int row, int col) const;

    int getSize() const;

    std::vector<Cell> getAdjacentNeighbors(int row, int col) const;

    bool inBoard(CellTypeEnum type) const;

    void removeStone() const;
};


#endif //LAYINGGRASS_BOARD_H