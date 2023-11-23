//
// Created by Baptiste Crepin on 11/11/2023.
//

#include <iostream>
#include "Board.h"
#include "enums/CellTypeEnum.h"
#define RESET   "\033[0m"
#define RED     "\033[31m"
#define GREEN   "\033[32m"
#define YELLOW  "\033[33m"
#define BLUE    "\033[34m"
#define MAGENTA "\033[35m"
#define CYAN    "\033[36m"

using namespace std;

Board::Board(int s) {
    size = s;

    // Création du tableau à deux dimensions
    grid = new Cell *[size];
    for (int i = 0; i < size; ++i) {
        grid[i] = new Cell[size];
    }

    // Initialisation du tableau avec des valeurs par défaut, par exemple des espaces
    for (int i = 0; i < size; ++i) {
        for (int j = 0; j < size; ++j) {
            grid[i][j] = Cell(i, j, "b", CellTypeEnum::Void);
        }
    }

    cout << "Board created" << endl;
    cout << grid[0][0].getType() << endl;
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
            std::string color = grid[i][j].getColor();

            switch (color[0]) {
                case 'r':
                    std::cout << RED << grid[i][j].getLabel() << " " << RESET;
                    break;
                case 'g':
                    std::cout << GREEN << grid[i][j].getLabel() << " " << RESET;
                    break;
                case 'y':
                    std::cout << YELLOW << grid[i][j].getLabel() << " " << RESET;
                    break;
                case 'b':
                    std::cout << BLUE << grid[i][j].getLabel() << " " << RESET;
                    break;
                case 'm':
                    std::cout << MAGENTA << grid[i][j].getLabel() << " " << RESET;
                    break;
                case 'c':
                    std::cout << CYAN << grid[i][j].getLabel() << " " << RESET;
                    break;
                default:
                    std::cout << grid[i][j].getLabel() << " ";
                    break;
            }
        }
        std::cout << std::endl;
    }
}

void Board::setValue(int row, int col, Cell value) const {
    bool valid = false;
    do {
        cout << row << " " << col << endl;
        if (row >= 0 && row < size && col >= 0 && col < size) {
            grid[row][col] = value;
            return;
        } else {
            cout << "Out of bounds !" << endl;
            cout << "Enter the coordinates of the stone to remove (x y): " << endl;
            cin >> row >> col;
        }
    } while (not valid);
}

Cell Board::getValue(int row, int col) const {
    if (row >= 0 && row < size && col >= 0 && col < size) {
        return grid[row][col];
    } else {
        std::cout << "Out of bounds !" << std::endl;
    }
}

int Board::getSize() const {
    return size;
}

std::vector<Cell> Board::getAdjacentNeighbors(int row, int col) const {
    std::vector<Cell> neighbors;

    // Relative positions of four adjacent neighbors (up, down, left, right)
    int dx[] = {-1, 0, 0, 1};
    int dy[] = {0, -1, 1, 0};

    for (int i = 0; i < 4; ++i) {
        int newRow = row + dx[i];
        int newCol = col + dy[i];

        // Check if the new position is within the bounds of the grid
        if (newRow >= 0 && newRow < this->getSize() && newCol >= 0 && newCol < this->getSize()) {
            neighbors.push_back(this->getValue(newRow, newCol));
        }
    }

    return neighbors;
}

bool Board::inBoard(CellTypeEnum type) const {
    for (int i = 0; i < this->getSize(); ++i) {
        for (int j = 0; j < this->getSize(); ++j) {
            if (this->getValue(i, j).getType() == type) {
                return true;
            }
        }
    }
    return false;
}

void Board::removeStone() const {
    this->display();
    int x, y;
    bool removed = false;
    do {
        std::cout << "Enter the coordinates of the stone to remove (x y): ";
        std::cin >> x >> y;
        if (this->getValue(x, y).getType() == CellTypeEnum::Stone_Tile) {
            this->setValue(x, y, Cell(x, y, "b", CellTypeEnum::Void));
            removed = true;
        } else {
            std::cout << "This is not a stone tile" << std::endl;
        }
    } while (not removed);
}