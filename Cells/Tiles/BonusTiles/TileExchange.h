//
// Created by Baptiste Crepin on 22/11/2023.
//

#ifndef LAYINGGRASS_TILEEXCHANGE_H
#define LAYINGGRASS_TILEEXCHANGE_H


#include "BonusTile.h"

class TileExchange : public BonusTile {
protected:
    int tilesPerPlayer = 1.5;

public:
    void applyBonus() override;

};


#endif //LAYINGGRASS_TILEEXCHANGE_H
