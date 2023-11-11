#include <iostream>
#include "Cells/Cell.h"
#include "Board.h"
using namespace std;

int main() {
    cout << "Hello, World!" << endl;
    
    Board board = Board(20);
    board.printBoard();
    cout << board.getSideWidth() << endl;
    cout << "End" << endl;
    return 0;
}
