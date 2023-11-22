//
// Created by Baptiste Crepin on 22/11/2023.
//

#include "TileExchange.h"

TileExchange::TileExchange(int x, int y, double tilesPerPlayer) : BonusTile(CellTypeEnum::Bonus_Exchange, x, y,
                                                                            tilesPerPlayer) {}

TileExchange::~TileExchange() {}

void TileExchange::applyBonus(Player &player) {
    player.setExchangeTickets(player.getExchangeTickets() + 1);
}
