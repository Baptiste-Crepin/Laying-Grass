//
// Created by Baptiste Crepin on 12/11/2023.
//

#include <iostream>
#include <cstdlib>
#include <ctime>
#include <string>
#include "Game.h"

using namespace std;

Game::Game(int playerCount, int turnLimit) :
        playerCount(playerCount),
        turnLimit(turnLimit),
        currentPlayerIndex(0),
        turnCount(0),
        GameEnded(false),
        playerTurnOrder(Game::randomizePlayerTurnOrder(playerCount)),
        board(Board(playerCount < 5 ? 20 : 30)),
        tileQueue(TileQueue(playerCount)) {}

int Game::getPlayerCount() const { return playerCount; }

int Game::getCurrentPlayerIndex() const { return currentPlayerIndex; }

int Game::getTurnCount() const { return turnCount; }

int Game::getTurnLimit() const { return turnLimit; }

Player *Game::getPlayerTurnOrder() const { return playerTurnOrder; }

bool Game::isGameEnded() const { return GameEnded; }

Board Game::getBoard() const { return board; }


void Game::setCurrentPlayerIndex(int currentPlayerIndex) { Game::currentPlayerIndex = currentPlayerIndex; }

void Game::setTurnCount(int turnCount) { Game::turnCount = turnCount; }

void Game::setGameEnded(bool gameState) { Game::GameEnded = gameState; }


void Game::newTurn() {
    cout << "Turn " << this->getTurnCount() << endl;

    do {
        cout << this->getCurrentPlayer().getId() << " | " << endl;
        this->getBoard().printBoard();
        
        cout << "Queue : " << endl;
        this->getTileQueue().displayQueue();
        this->setNextPlayer();

        //todo: ask player if he wants to exchange a tile (if he has a ticket to exchange)
        cout << tileQueue.tileExchange().getId() << endl;
        tileQueue.nextTile();

    } while ((this->getCurrentPlayerIndex() < this->getPlayerCount()));


    this->setTurnCount(this->getTurnCount() + 1);
}

Player Game::getCurrentPlayer() {
    return this->getPlayerTurnOrder()[this->getCurrentPlayerIndex()];
}

//region: Private methods

Player *Game::randomizePlayerTurnOrder(int playerCount) {
    //gets a seed based on the current time for the rand() function
    srand(static_cast<unsigned>(time(nullptr)));

    Player *playerTurnOrder = new Player[playerCount];
    string name = "Test"; // Todo: get this a variable from the player
    for (int i = 0; i <= playerCount; i++) playerTurnOrder[i] = Player(i);
    for (int i = 0; i <= playerCount; i++) {
        int randomIndex = rand() % playerCount;
        Player temp = playerTurnOrder[i];
        playerTurnOrder[i] = playerTurnOrder[randomIndex];
        playerTurnOrder[randomIndex] = temp;
    }
    return playerTurnOrder;
}

void Game::setNextPlayer() {
    this->setCurrentPlayerIndex((this->getCurrentPlayerIndex() + 1) % this->getPlayerCount() + 1);
}


void Game::setTileQueue(const TileQueue &tileQueue) {
    Game::tileQueue = tileQueue;
}

const TileQueue &Game::getTileQueue() const { return this->tileQueue; }
