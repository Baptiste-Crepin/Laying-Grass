//
// Created by Baptiste Crepin on 18/11/2023.
//

#include "TileQueue.h"
#include <iostream>

TileQueue::TileQueue(int nbPlayers) {
    generateQueue(nbPlayers);
}

TileQueue::~TileQueue() {}

float TileQueue::getTilesPerPLayer() const { return tilesPerPLayer; }

int TileQueue::getDisplayedTiles() const { return displayedTiles; }

void TileQueue::displayQueue() {
    for (int i = 0; i < displayedTiles; i++) {
        std::cout << "Tile " << i << " : " << queue[i].getId() << std::endl;
    }
}

// private methods

void TileQueue::generateQueue(int nbPlayers) {
    int nbTiles = round(nbPlayers * tilesPerPLayer);

    //create queue
    Tile *tempQueue = new Tile[nbTiles];
    for (int i = 0; i < nbTiles; i++) {
        tempQueue[i] = Tile(i);
    }

    //randomize queue
    for (int i = 0; i <= nbTiles; i++) {
        int randomIndex = rand() % nbTiles;
        Tile temp = tempQueue[i];
        tempQueue[i] = tempQueue[randomIndex];
        tempQueue[randomIndex] = temp;
    }

    queue = tempQueue;
}