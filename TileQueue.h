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
    int totalTiles;
    int currentTileIndex;

private:

    void generateQueue(int nbPlayers);

public:
    Tile tileExchange();

    TileQueue(int nbPlayers);

    ~TileQueue();

    int getDisplayedTiles() const;


    int getTotalTiles() const;

    Tile getCurrentTile() const;

    Tile *getQueue() const;

    void displayQueue() const;


    void nextTile();

    int getCurrentTileIndex() const;


    void setCurrentTileIndex(int currentTileIndex);

    int selectTileExchangeIndex();

};


#endif //LAYINGGRASS_TILEQUEUE_H
