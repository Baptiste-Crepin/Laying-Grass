#include <iostream>
#include "Game.h"
using namespace std;

int main() {
    Game game = Game(6);
    game.getBoard().printBoard();
    return 0;
}
