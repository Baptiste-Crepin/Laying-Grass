//
// Created by Baptiste Crepin on 22/11/2023.
//

#include "TileExchange.h"
#include <iostream>

TileExchange::TileExchange(int x, int y, double tilesPerPlayer) : BonusTile(CellTypeEnum::Bonus_Exchange, x, y,
                                                                            tilesPerPlayer) {}

TileExchange::~TileExchange() {}

void TileExchange::applyBonus() {
    std::cout << "TileExchange::applyBonus()" << std::endl;

    // TODO implement here
}
