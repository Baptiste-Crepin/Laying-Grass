//
// Created by martin on 19/11/2023.
//

#include <iostream>
#include "Rotate_90.h"
#include <vector>

std::vector<std::vector<char>> rotation90(const std::vector<std::vector<char>>& matrix) {
    if (matrix.empty() || matrix[0].empty()) {
        std::cout << "Tableau vide ou sans colonnes." << std::endl;
        return matrix;
    }

    int rows = matrix.size();
    int cols = matrix[0].size();

    std::vector<std::vector<char>> temp(cols, std::vector<char>(rows));

    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            temp[j][rows - 1 - i] = matrix[i][j];
        }
    }

    return temp;
}