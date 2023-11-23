//
// Created by martin on 23/11/2023.
//

#include "victory_condition.h"
#include <algorithm>
#include <vector>

using namespace std;

Square SquareFinder::findLargestSquare(const std::vector<std::vector<int>>& matrix) {
    int rows = matrix.size();
    if (rows == 0) {
        return {0, -1, -1};
    }
    int cols = matrix[0].size();

    std::vector<std::vector<int>> dp(rows, std::vector<int>(cols, 0));
    int maxSize = 0;
    int maxRow = -1, maxCol = -1;

    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            if (i == 0 || j == 0) {
                dp[i][j] = matrix[i][j];
            } else if (matrix[i][j] == 1) {
                dp[i][j] = std::min({dp[i - 1][j], dp[i][j - 1], dp[i - 1][j - 1]}) + 1;
            }

            if (dp[i][j] > maxSize) {
                maxSize = dp[i][j];
                maxRow = i - maxSize + 1;
                maxCol = j - maxSize + 1;
            }
        }
    }

    return {maxSize, maxRow, maxCol};
}

// A ajouter a la fin de la partie

//SquareFinder squareFinder;
//Square result = squareFinder.findLargestSquare(matrix);
//
//if (result.size > 0) {
//std::cout << "Found a square of size " << result.size << " at coordinates (" << result.row << ", " << result.col << ").\n";
//} else {
//std::cout << "No square of 1s found.\n";
//}
//
//return 0;