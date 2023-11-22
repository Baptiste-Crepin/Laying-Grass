//
// Created by Baptiste Crepin on 22/11/2023.
//

#ifndef LAYINGGRASS_TILEEXCHANGE_H
#define LAYINGGRASS_TILEEXCHANGE_H


#include "BonusTile.h"
#include "../../../Player.h"

class TileExchange : public BonusTile {
public:
    explicit TileExchange(int x = 0, int y = 0, double tilesPerPlayer = 1.5);

    ~TileExchange() override;

    void applyBonus(Player &player) override;
};


#endif //LAYINGGRASS_TILEEXCHANGE_H
