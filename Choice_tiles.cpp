//
// Created by martin on 20/11/2023.
//

#include "Choice_tiles.h"
#include "Rotate_90.h"
#include "Vertical_symmetry.h"

#include <iostream>
#include <vector>

using namespace std;

std::vector<std::vector<char>> choice_tiles(const std::vector<std::vector<char>>& matrix) {
    cout << "Tile to place" << endl;
    char t = -2;
    for (const auto &row: matrix) {
            for (char val: row) {
                if (val == '1')
                    std::cout << t << " ";
            }
            std::cout << std::endl;
        }

    cout << "Flip tile (F)" << endl;
    cout << "Rotate tile (R)" << endl;
    cout << "Place tile (P)" << endl;

    char choice;
    cin >> choice;

    switch (choice) {
        case 'F':
            choice_tiles(vertical_symmetry(matrix));
            break;
        case 'R':
            choice_tiles(rotate90(matrix));
            break;
        case 'P':
            cout << "Tile placed" << endl;
            return matrix;
            break;
        default:
            cout << "Invalid choice" << endl;
            break;
    }
    return matrix;
}
