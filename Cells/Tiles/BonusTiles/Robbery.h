//
// Created by Baptiste Crepin on 22/11/2023.
//

#ifndef LAYINGGRASS_ROBBERY_H
#define LAYINGGRASS_ROBBERY_H


#include "BonusTile.h"

class Robbery : public BonusTile {
public:
    explicit Robbery(double tilesPerPlayer = 1);

    static void applyBonus();

};


#endif //LAYINGGRASS_ROBBERY_H
