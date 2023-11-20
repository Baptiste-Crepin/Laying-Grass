//
// Created by martin on 19/11/2023.
//

#include "Vertical_symmetry.h"
#include <algorithm>
#include <iostream>
#include <vector>

std::vector<std::vector<char>> symetrieVerticale(const std::vector<std::vector<char>>& matrix) {
    if (matrix.empty() || matrix[0].empty()) {
        std::cout << "Tableau vide ou sans colonnes." << std::endl;
        return matrix;
    }

    std::vector<std::vector<char>> symetrie = matrix;

    std::reverse(symetrie.begin(), symetrie.end());

    return symetrie;
}