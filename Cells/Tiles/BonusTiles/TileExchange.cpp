//
// Created by Baptiste Crepin on 22/11/2023.
//

#include "TileExchange.h"

TileExchange::TileExchange(double tilesPerPlayer) : BonusTile(CellTypeEnum::Bonus_Exchange, tilesPerPlayer) {}

TileExchange::~TileExchange() {}

void TileExchange::applyBonus() {
    // TODO implement here
}
