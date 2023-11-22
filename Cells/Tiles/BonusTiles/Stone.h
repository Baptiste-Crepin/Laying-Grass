//
// Created by Baptiste Crepin on 22/11/2023.
//

#ifndef LAYINGGRASS_STONE_H
#define LAYINGGRASS_STONE_H


#include "BonusTile.h"

class Stone : public BonusTile {

public:
    explicit Stone(int x = 0, int y = 0, double tilesPerPlayer = 0.5);

    void applyBonus() override;
};


#endif //LAYINGGRASS_STONE_H
