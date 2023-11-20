//
// Created by Baptiste Crepin on 11/11/2023.
//

#include <iostream>
#include "board.h"

Board::Board(int s) {
    size = s;

    // Création du tableau à deux dimensions
    grid = new char *[size];
    for (int i = 0; i < size; ++i) {
        grid[i] = new char[size];
    }

    // Initialisation du tableau avec des valeurs par défaut, par exemple des espaces
    for (int i = 0; i < size; ++i) {
        for (int j = 0; j < size; ++j) {
            grid[i][j] = '0';
        }
    }

    std::cout << "Board created" << std::endl;
    std::cout << grid[0][0] << std::endl;
}

Board::~Board() {
    // Libération de la mémoire allouée pour le tableau
//    for (int i = 0; i < size; ++i) {
//        delete[] grid[i];
//    }
//    delete[] grid;
}

void Board::display() {
    for (int i = 0; i < size; ++i) {
        for (int j = 0; j < size; ++j) {
            std::cout << grid[i][j] << " ";
        }
        std::cout << std::endl;
    }
}

void Board::setValue(int row, int col, char value) {
    if (row >= 0 && row < size && col >= 0 && col < size) {
        grid[row][col] = value;
    } else {
        std::cout << "Indices hors limites !" << std::endl;
    }
}

char Board::getValue(int row, int col) {
    if (row >= 0 && row < size && col >= 0 && col < size) {
        return grid[row][col];
    } else {
        std::cout << "Indices hors limites !" << std::endl;
        return '\0';
    }
}


int Board::getSize() const {
    return size;
}