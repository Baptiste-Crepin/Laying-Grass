#include <iostream>
#include "Game.h"
#include "victory_condition.h"

using namespace std;

int main() {
    Game game = Game::initializeGame();
    game.startGame();

//    std::vector<std::vector<char>> tableau = retreiveTileLayout();
//    //TEST ROTAION SYMETRIE
//    for (const auto &row: tableau) {
//        for (char val: row) {
//            std::cout << val << " ";
//        }
//        std::cout << std::endl;
//    }
//    tableau = symetrieVerticale(tableau);
//    for (const auto &row: tableau) {
//        for (char val: row) {
//            std::cout << val << " ";
//        }
//        std::cout << std::endl;
//    }
}