//
// Created by martin on 19/11/2023.
//

#include "Rotate_n90.h"
#include <vector>
#include <iostream>

std::vector<std::vector<char>> rotationMinus90(const std::vector<std::vector<char>>& matrix) {
    if (matrix.empty() || matrix[0].empty()) {
        std::cout << "Tableau vide ou sans colonnes." << std::endl;
        return matrix;
    }

    int rows = matrix.size();
    int cols = matrix[0].size();

    std::vector<std::vector<char>> temp(cols, std::vector<char>(rows));

    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            temp[cols - 1 - j][i] = matrix[i][j];
        }
    }

    return temp;
}