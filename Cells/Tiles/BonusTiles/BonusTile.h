//
// Created by Baptiste Crepin on 22/11/2023.
//

#ifndef LAYINGGRASS_BONUSTILE_H
#define LAYINGGRASS_BONUSTILE_H


class BonusTile {
protected:
    double tilesPerPlayer;
    char Label;

public:
    explicit BonusTile(char label = 'B', double tilesPerPlayer = 0);

    double getTilesPerPlayer() const;

    virtual void applyBonus() = 0;

    virtual ~BonusTile();

    char getLabel();
};


#endif //LAYINGGRASS_BONUSTILE_H
