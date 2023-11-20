//
// Created by Baptiste Crepin on 18/11/2023.
//

#include "TileQueue.h"
#include <iostream>
#include <iomanip>

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
    for (int i = this->getCurrentTileIndex(); i < this->getDisplayedTiles() + this->getCurrentTileIndex(); i++) {
        cout << std::setw(2) << this->getQueue()[i % this->getTotalTiles()].getId() << " | ";
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

Tile TileQueue::tileExchange() {
    cout << "Choose a tile to exchange : " << endl;
    this->displayQueue();
    for (int i = 0; i < this->getDisplayedTiles(); i++) {
        cout << std::setw(2) << i + 1 << " | ";
    }
    cout << endl;


//    int selectedTile;
//    do {
//        cout << "Please enter a number between 1 and 6" << endl;
//        cin >> selectedTile;
//    } while (not(selectedTile >= 1 && selectedTile <= 5));

    int selectedTile = selectTileExchangeIndex();

    //todo input number between 1 - 6
//    int x = selectedTile;
    this->setCurrentTileIndex((this->getCurrentTileIndex() + selectedTile) % (this->getTotalTiles() + 1));
    return this->getCurrentTile();
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

int TileQueue::selectTileExchangeIndex() {
    int selectedTile;
    do {
        cout << "Please enter a number between 1 and 6" << endl;
        cin >> selectedTile;
    } while (not(selectedTile >= 1 && selectedTile <= 5));
    return selectedTile;
}