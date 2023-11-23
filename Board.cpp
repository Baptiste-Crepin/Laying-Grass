//
// Created by Baptiste Crepin on 11/11/2023.
//

#include <iostream>
#include "Board.h"
#include "enums/CellTypeEnum.h"
#include <iomanip>
#include "Game.h"

#define RESET   "\033[0m"
#define RED     "\033[38;2;255;0;0m"
#define GREEN   "\033[38;2;0;255;0m"
#define YELLOW  "\033[38;2;255;255;0m"
#define BLUE    "\033[38;2;0;0;255m"
#define MAGENTA "\033[38;2;255;0;255m"
#define CYAN    "\033[38;2;0;255;255m"
#define ORANGE  "\033[38;2;255;165;0m"
#define PURPLE  "\033[38;2;128;0;128m"
#define TURQUOISE "\033[38;2;64;224;208m"

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
            grid[i][j] = Cell(i, j, "", CellTypeEnum::Void);
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
    // Affichage des indices de colonnes
    std::cout << "   "; // Espace pour l'alignement avec les colonnes
    for (int i = 0; i < size; ++i) {
        char colIndex = 'A' + i; // Convertir l'indice en lettre (A, B, C, ...)
        std::cout << colIndex << " ";
    }
    std::cout << std::endl;

    for (int i = 0; i < size; ++i) {
        // Affichage de l'indice de ligne et début de la bordure gauche
//        char rowIndex = 'A' + i; // Convertir l'indice en lettre (A, B, C, ...)
        std::cout << std::setw(2) << i << "|";

        for (int j = 0; j < size; ++j) {
            std::string color = grid[i][j].getColor();

            switch (color[0]) {
                case 'r':
                    std::cout << RED << grid[i][j].getTileId() << RESET;
                    break;
                case 'g':
                    std::cout << GREEN << grid[i][j].getTileId() << RESET;
                    break;
                case 'y':
                    std::cout << YELLOW << grid[i][j].getTileId() << RESET;
                    break;
                case 'b':
                    std::cout << BLUE << grid[i][j].getTileId() << RESET;
                    break;
                case 'm':
                    std::cout << MAGENTA << grid[i][j].getTileId() << RESET;
                    break;
                case 'c':
                    std::cout << CYAN << grid[i][j].getTileId() << RESET;
                    break;
                case 'o':
                    std::cout << ORANGE << grid[i][j].getTileId() << RESET;
                    break;
                case 'p':
                    std::cout << PURPLE << grid[i][j].getTileId() << RESET;
                    break;
                case 't':
                    std::cout << TURQUOISE << grid[i][j].getTileId() << RESET;
                    break;
                default:
                    Cell currentCell = grid[i][j];
                    std::cout << currentCell.getLabel();
                    break;
            }

            std::cout << " "; // Espace entre chaque colonne
        }

        std::cout << "|"; // Bordure droite et nouvelle ligne
        std::cout << std::endl;
    }

    // Affichage de la bordure supérieure
    std::cout << "  "; // Espace pour l'alignement avec les colonnes
    for (int i = 0; i < size; ++i) {
        std::cout << "-" << " ";
    }
    std::cout << std::endl;
}

//return the value of each cell and transform it into a int in a board
std::vector<std::vector<int>> Board::getBoard() const {
    std::vector<std::vector<int>> board;
    for (int i = 0; i < size; ++i) {
        std::vector<int> row;
        for (int j = 0; j < size; ++j) {
            row.push_back(grid[i][j].getfill());
        }
        board.push_back(row);
    }
    return board;
}

//get the color of the cell at x and y
std::string Board::getColor(int x, int y) const {
    return grid[x][y].getColor();
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
        std::cout << "Enter the coordinates of the stone to remove: ";
        char tempChar;
        std::cin >> x;
        std::cin >> tempChar;
        y = Game::charToInt(tempChar);
        if (this->getValue(x, y).getType() == CellTypeEnum::Stone_Tile) {
            this->setValue(x, y, Cell(x, y, "", CellTypeEnum::Void));
            removed = true;
        } else {
            std::cout << "This is not a stone tile" << std::endl;
        }
    } while (not removed);
}