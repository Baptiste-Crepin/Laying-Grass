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
    std::vector<std::vector<std::shared_ptr<Cell>>> grid;

public:
    Board(int s);

    ~Board();

    void display() const;

    void setValue(int row, int col, const std::shared_ptr<Cell> &value);
    
    std::shared_ptr<Cell> getValue(int row, int col) const;

    int getSize() const;

    std::vector<std::shared_ptr<Cell>> getAdjacentNeighbors(int row, int col) const;

    const std::vector<std::vector<std::shared_ptr<Cell>>> &getGrid() const;
//    const std::vector<std::vector<std::shared_ptr<Cell>>> &getValue() const;

};


#endif //LAYINGGRASS_BOARD_H