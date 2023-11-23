//
// Created by martin on 23/11/2023.
//

#ifndef LAYINGGRASS_VICTORY_CONDITION_H
#define LAYINGGRASS_VICTORY_CONDITION_H


#include <vector>

struct Square {
    int size;
    int row;
    int col;
};

class SquareFinder {
public:
    Square findLargestSquare(const std::vector<std::vector<int>>& matrix);
};

#endif //LAYINGGRASS_VICTORY_CONDITION_H
