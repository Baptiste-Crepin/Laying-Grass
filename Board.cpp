//
// Created by Baptiste Crepin on 11/11/2023.
//

#include <iostream>
#include "Board.h"
#include "enums/CellTypeEnum.h"

using namespace std;

Board::Board(int s) : size(s) {
    // Initialize the grid with shared pointers to Cell
    grid.resize(size, std::vector<std::shared_ptr<Cell>>(size, nullptr));

    // Initialize each element with a new Cell
    for (int i = 0; i < size; ++i) {
        for (int j = 0; j < size; ++j) {
            grid[i][j] = std::make_shared<Cell>(i, j, CellTypeEnum::Void);
        }
    }

    std::cout << "Board created" << std::endl;
    std::cout << grid[0][0]->getType() << std::endl;
}

Board::~Board() {
    // Libération de la mémoire allouée pour le tableau
//    for (int i = 0; i < size; ++i) {
//        delete[] grid[i];
//    }
//    delete[] grid;
}

void Board::display() const {
    for (int i = 0; i < size; ++i) {
        for (int j = 0; j < size; ++j) {
            std::cout << grid[i][j]->getLabel() << " ";
        }
        std::cout << std::endl;
    }
}

//void Board::setValue(int row, int col, const Cell &value) const {
//    if (row >= 0 && row < size && col >= 0 && col < size) {
//        grid[row][col] = value;
//    } else {
//        std::cout << "Indices hors limites !" << std::endl;
//    }
//}

void Board::setValue(int row, int col, const std::shared_ptr<Cell> &value) {
    if (row >= 0 && row < size && col >= 0 && col < size) {
        grid[row][col] = value;
    } else {
        std::cout << "Indices hors limites !" << std::endl;
    }
}

std::shared_ptr<Cell> Board::getValue(int row, int col) const {
    if (row >= 0 && row < size && col >= 0 && col < size) {
        return grid[row][col];
    } else {
        std::cout << "Indices hors limites !" << std::endl;
        //Todo: handle this case
        return nullptr;
    }
}

int Board::getSize() const { return size; }

vector<shared_ptr<Cell>> Board::getAdjacentNeighbors(int row, int col) const {
    vector<shared_ptr<Cell>> neighbors;

    // Relative coordinates (up, down, left, right)
    int dx[] = {-1, 0, 0, 1};
    int dy[] = {0, -1, 1, 0};

    for (int i = 0; i < 4; ++i) {
        int newRow = row + dx[i];
        int newCol = col + dy[i];

        if (newRow >= 0 && newRow < this->getSize() && newCol >= 0 && newCol < this->getSize()) {
            neighbors.push_back(this->getGrid()[newRow][newCol]);

        }
    }

    return neighbors;
}

const vector<std::vector<std::shared_ptr<Cell>>> &Board::getGrid() const {
    return grid;
}
