//
// Created by Baptiste Crepin on 11/11/2023.
//

#include <iostream>
#include "Board.h"

using namespace std;

Board::Board(int sideWidth) : sideWidth(sideWidth) {
    cout << "Board constructor" << endl;
    cellsLayout = new Cell**[sideWidth];
    for (int i = 0; i < sideWidth; ++i) {
        cellsLayout[i] = new Cell*[sideWidth];
        for (int j = 0; j < sideWidth; ++j) {
            cellsLayout[i][j] = new Cell(i, j, Void);
        }
    }
}

Board::~Board() {
    for (int i = 0; i < sideWidth; ++i) {
        delete[] cellsLayout[i];
    }
    delete[] cellsLayout;
}

int Board::getSideWidth() const {return sideWidth;}
Cell*** Board::getCellsLayout() const {return cellsLayout;}


void Board::printBoard() {
    cout << "Print" << endl;
    for (int i = 0; i < sideWidth; ++i) {
        for (int j = 0; j < sideWidth; ++j) {
            cout << cellsLayout[i][j]->getType() << " ";
        }
        cout << endl;
    }
}