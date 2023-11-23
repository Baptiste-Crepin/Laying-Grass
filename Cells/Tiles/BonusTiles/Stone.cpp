//
// Created by Baptiste Crepin on 22/11/2023.
//

#include "Stone.h"
#include <iostream>

using namespace std;

Stone::Stone(double tilesPerPlayer) : BonusTile(CellTypeEnum::Bonus_Stone, tilesPerPlayer) {}

void Stone::applyBonus() {

    cout << "Stone bonus applied" << endl;
}