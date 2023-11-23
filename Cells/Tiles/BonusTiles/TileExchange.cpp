//
// Created by Baptiste Crepin on 22/11/2023.
//

#include "TileExchange.h"
#include <iostream>

using namespace std;

TileExchange::TileExchange(double tilesPerPlayer) : BonusTile(CellTypeEnum::Bonus_Exchange, tilesPerPlayer) {}

TileExchange::~TileExchange() {}

void TileExchange::applyBonus(Player &player) {
    cout << "TileExchange bonus applied" << endl;
    player.setExchangeTickets(player.getExchangeTickets() + 1);
}
