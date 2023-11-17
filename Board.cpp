//
// Created by Baptiste Crepin on 11/11/2023.
//

#include <iostream>
#include "Board.h"

using namespace std;

Board::Board(int sideWidth) : sideWidth(sideWidth) {
    // Allocate memory for the 2D array
    cellsLayout = new Cell*[sideWidth];
    for (int i = 0; i < sideWidth; ++i) {
        cellsLayout[i] = new Cell[sideWidth];

        // Initialize each Cell with the valid values
        for (int j = 0; j < sideWidth; ++j) {
            cellsLayout[i][j] = Cell(i, j, Void);
        }
    }
}
Board::~Board() {
//TODO: fix this destructor, right now it crashes the program when called

//    for (int i = 0; i < sideWidth; ++i) {
//        delete[] cellsLayout[i];
//    }
//    delete[] cellsLayout;
}

int Board::getSideWidth() const {return sideWidth;}
Cell** Board::getCellsLayout() const {return this->cellsLayout;}


void Board::printBoard() {
    for (int i = 0; i < sideWidth; i++) {
        for (int j = 0; j < sideWidth; j++) {
            cout << cellsLayout[i][j].getType() << " ";
        }
        cout << i+1 <<endl;
    }
}