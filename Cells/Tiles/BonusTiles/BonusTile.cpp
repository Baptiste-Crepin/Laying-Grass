//
// Created by Baptiste Crepin on 22/11/2023.
//

#include "BonusTile.h"

BonusTile::BonusTile(char label, double tilesPerPlayer) : Label(label), tilesPerPlayer(tilesPerPlayer) {}

BonusTile::~BonusTile() {}

double BonusTile::getTilesPerPlayer() const { return tilesPerPlayer; }

char BonusTile::getLabel() { return Label; }
