//
// Created by Baptiste Crepin on 22/11/2023.
//

#ifndef LAYINGGRASS_ROBBERY_H
#define LAYINGGRASS_ROBBERY_H


#include "BonusTile.h"

class Robbery : public BonusTile {
protected:
    int tilesPerPlayer = 1;

public:
    void applyBonus() override;

};


#endif //LAYINGGRASS_ROBBERY_H
