#include <iostream>
#include "Cells/Cell.h"

using namespace std;

int main() {
    cout << "Hello, World!" << endl;

    Cell cell(0, 0, Grass);
    cout << cell.getType() << endl;
    return 0;
}
