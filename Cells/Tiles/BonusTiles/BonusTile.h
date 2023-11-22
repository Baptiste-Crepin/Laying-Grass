//
// Created by Baptiste Crepin on 22/11/2023.
//

#ifndef LAYINGGRASS_BONUSTILE_H
#define LAYINGGRASS_BONUSTILE_H


#include "../../../enums/CellTypeEnum.h"
#include "../../Cell.h"

class BonusTile : public Cell {
protected:
    double tilesPerPlayer;

public:
    explicit BonusTile(CellTypeEnum type, int x = 0, int y = 0, double tilesPerPlayer = 0);

    double getTilesPerPlayer() const;

    virtual void applyBonus();

    virtual ~BonusTile();
};


#endif //LAYINGGRASS_BONUSTILE_H
