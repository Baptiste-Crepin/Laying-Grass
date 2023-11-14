#include <iostream>
#include "Game.h"
using namespace std;

int main() {
    Game game = Game(3);
    while (!game.isGameEnded() && game.getTurnCount() <= game.getTurnLimit())
    {
        game.newTurn();
    }
    cout << "Game ended" << endl;
    return 0;
}
