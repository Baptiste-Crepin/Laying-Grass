//
// Created by martin on 19/11/2023.
//

#include "Horizontal_symmetry.h"
#include <iostream>
#include <vector>
#include <algorithm>

std::vector<std::vector<char>> horizontal_symmetry(const std::vector<std::vector<char>>& matrix) {
    if (matrix.empty() || matrix[0].empty()) {
        std::cout << "Tableau vide ou sans colonnes." << std::endl;
        return matrix;
    }

    std::vector<std::vector<char>> symmetry = matrix;

    int rows = symmetry.size();

    for (int i = 0; i < rows; ++i) {
        std::reverse(symmetry[i].begin(), symmetry[i].end());
    }

    return symmetry;
}
