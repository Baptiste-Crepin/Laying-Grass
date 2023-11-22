//
// Created by Baptiste Crepin on 22/11/2023.
//

#ifndef LAYINGGRASS_STONE_H
#define LAYINGGRASS_STONE_H


#include "BonusTile.h"

class Stone : public BonusTile {
protected:
    int tilesPerPlayer = 0.5;

public:
    void applyBonus() override;

};


#endif //LAYINGGRASS_STONE_H
