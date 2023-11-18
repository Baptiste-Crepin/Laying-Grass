//
// Created by Baptiste Crepin on 18/11/2023.
//

#include "TileQueue.h"
#include <iostream>

using namespace std;

TileQueue::TileQueue(int nbPlayers) : totalTiles(round(nbPlayers * tilesPerPLayer)), currentTileIndex(0) {
    generateQueue(nbPlayers);
}

TileQueue::~TileQueue() {
//    cout << "deleted" << endl;
}

Tile *TileQueue::getQueue() const { return queue; }

int TileQueue::getDisplayedTiles() const { return displayedTiles; }

void TileQueue::displayQueue() const {
    cout << "Queue : " << endl;
    for (int i = this->getCurrentTileIndex(); i < this->getDisplayedTiles() + this->getCurrentTileIndex(); i++) {
        cout << this->getQueue()[i % this->getTotalTiles()].getId() << " | ";
    }
    cout << endl;
}

int TileQueue::getTotalTiles() const { return totalTiles; }

Tile TileQueue::getCurrentTile() const {
    return queue[this->getCurrentTileIndex()];
}

void TileQueue::nextTile() {
    this->setCurrentTileIndex((this->getCurrentTileIndex() + 1) % (this->getTotalTiles() + 1));
}

int TileQueue::getCurrentTileIndex() const {
    return currentTileIndex;
}

void TileQueue::setCurrentTileIndex(int currentTileIndex) {
    TileQueue::currentTileIndex = currentTileIndex;
}

// private methods

void TileQueue::generateQueue(int nbPlayers) {

    //create queue
    Tile *tempQueue = new Tile[this->getTotalTiles()];
    for (int i = 0; i < this->getTotalTiles(); i++) {
        tempQueue[i] = Tile(i);
    }

    //randomize queue
    for (int i = 0; i <= this->getTotalTiles(); i++) {
        int randomIndex = rand() % this->getTotalTiles();
        Tile temp = tempQueue[i];
        tempQueue[i] = tempQueue[randomIndex];
        tempQueue[randomIndex] = temp;
    }

    queue = tempQueue;
}