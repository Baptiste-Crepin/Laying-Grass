//
// Created by Baptiste Crepin on 22/11/2023.
//

#ifndef LAYINGGRASS_BONUSTILE_H
#define LAYINGGRASS_BONUSTILE_H


class BonusTile {
protected:
    int tilesPerPlayer = 0;
public:
    explicit BonusTile(int tilesPerPlayer);

    int getTilesPerPlayer() const;

public:
    virtual void applyBonus() = 0;

    virtual ~BonusTile();
};


#endif //LAYINGGRASS_BONUSTILE_H
