//
// Created by Baptiste Crepin on 22/11/2023.
//

#include "BonusTile.h"
#include <iostream>


BonusTile::BonusTile(CellTypeEnum type, int x, int y, double tilesPerPlayer) : Cell(x, y, type),
                                                                               tilesPerPlayer(tilesPerPlayer) {}

BonusTile::~BonusTile() {}

double BonusTile::getTilesPerPlayer() const { return tilesPerPlayer; }

void BonusTile::applyBonus() {
    std::cout << "BonusTile::applyBonus()" << std::endl;
    // TODO implement here
}
