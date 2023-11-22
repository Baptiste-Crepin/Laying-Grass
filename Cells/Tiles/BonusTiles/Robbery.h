//
// Created by Baptiste Crepin on 22/11/2023.
//

#ifndef LAYINGGRASS_ROBBERY_H
#define LAYINGGRASS_ROBBERY_H


#include "BonusTile.h"

class Robbery : public BonusTile {
public:
    explicit Robbery(char label = 'R', double tilesPerPlayer = 1);

    void applyBonus() override;

};


#endif //LAYINGGRASS_ROBBERY_H
