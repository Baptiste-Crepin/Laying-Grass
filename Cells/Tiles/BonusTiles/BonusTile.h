//
// Created by Baptiste Crepin on 22/11/2023.
//

#ifndef LAYINGGRASS_BONUSTILE_H
#define LAYINGGRASS_BONUSTILE_H


#include "../../../enums/CellTypeEnum.h"

class BonusTile {
protected:
    double tilesPerPlayer;
    CellTypeEnum type;

public:
    explicit BonusTile(CellTypeEnum type, double tilesPerPlayer = 0);

    double getTilesPerPlayer() const;

    virtual ~BonusTile();

    CellTypeEnum getType();
};


#endif //LAYINGGRASS_BONUSTILE_H
