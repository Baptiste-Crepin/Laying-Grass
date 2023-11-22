//
// Created by Baptiste Crepin on 22/11/2023.
//

#include "Robbery.h"
#include <iostream>

using namespace std;

Robbery::Robbery(double tilesPerPlayer) : BonusTile(CellTypeEnum::Bonus_Robbery, tilesPerPlayer) {}


void Robbery::applyBonus() {
    cout << "Robbery bonus applied" << endl;
}