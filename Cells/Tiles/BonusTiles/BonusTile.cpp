//
// Created by Baptiste Crepin on 22/11/2023.
//

#include "BonusTile.h"

BonusTile::BonusTile(CellTypeEnum type, double tilesPerPlayer) : type(type), tilesPerPlayer(tilesPerPlayer) {}

BonusTile::~BonusTile() {}

double BonusTile::getTilesPerPlayer() const { return tilesPerPlayer; }

CellTypeEnum BonusTile::getType() { return type; }
