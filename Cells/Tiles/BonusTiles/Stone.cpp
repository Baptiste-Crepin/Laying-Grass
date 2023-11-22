//
// Created by Baptiste Crepin on 22/11/2023.
//

#include "Stone.h"

Stone::Stone(int x, int y, double tilesPerPlayer) : BonusTile(CellTypeEnum::Bonus_Stone, x, y, tilesPerPlayer) {}

void Stone::applyBonus() {
    // TODO implement here
}