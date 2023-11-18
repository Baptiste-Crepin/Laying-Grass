//
// Created by Baptiste Crepin on 18/11/2023.
//

#ifndef LAYINGGRASS_TILEQUEUE_H
#define LAYINGGRASS_TILEQUEUE_H


#include "Cells/Tiles/Tile.h"

class TileQueue {
private:
    float tilesPerPLayer = 10.67;
    int displayedTiles = 6;
    Tile *queue;

    void generateQueue(int nbPlayers);

public:
    TileQueue(int nbPlayers);

    ~TileQueue();

    float getTilesPerPLayer() const;

    int getDisplayedTiles() const;

    void displayQueue();
};


#endif //LAYINGGRASS_TILEQUEUE_H
