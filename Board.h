//
// Created by Baptiste Crepin on 11/11/2023.
//

#ifndef LAYINGGRASS_BOARD_H
#define LAYINGGRASS_BOARD_H


#include "Cells/Cell.h"

class Board {
private:
    int sideWidth; // the board is always a square
    Cell** cellsLayout;

public:
    Board(int sideWidth);
    ~Board();

    int getSideWidth() const;
    Cell** getCellsLayout() const;

    void setCellsLayout(Cell** cellsLayout);

    void printBoard();
};


#endif //LAYINGGRASS_BOARD_H
