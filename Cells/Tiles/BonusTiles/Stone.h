//
// Created by Baptiste Crepin on 22/11/2023.
//

#ifndef LAYINGGRASS_STONE_H
#define LAYINGGRASS_STONE_H


#include "BonusTile.h"

class Stone : public BonusTile {

public:
    explicit Stone(double tilesPerPlayer = 0.5);

    static void applyBonus();
};


#endif //LAYINGGRASS_STONE_H
