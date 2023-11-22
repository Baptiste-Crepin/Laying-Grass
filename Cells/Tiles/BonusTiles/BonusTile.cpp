//
// Created by Baptiste Crepin on 22/11/2023.
//

#include "BonusTile.h"

BonusTile::BonusTile(int tilesPerPlayer) : tilesPerPlayer(tilesPerPlayer) {}

BonusTile::~BonusTile() {}

int BonusTile::getTilesPerPlayer() const { return tilesPerPlayer; }


