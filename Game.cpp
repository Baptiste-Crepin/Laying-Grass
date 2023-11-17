//
// Created by Baptiste Crepin on 12/11/2023.
//

#include <iostream>
#include <cstdlib>
#include <ctime>
#include "Game.h"

using namespace std;

Game::Game(int playerCount, int turnLimit) :
    playerCount(playerCount),
    turnLimit(turnLimit),
    currentPlayerIndex(0),
    turnCount(0),
    GameEnded(false),
    playerTurnOrder(Game::randomizePlayerTurnOrder(playerCount)),
    board(Board(playerCount < 5 ? 20: 30))
    {}

int Game::getPlayerCount() const {return playerCount;}
int Game::getCurrentPlayerIndex() const {return currentPlayerIndex;}
int Game::getTurnCount() const {return turnCount;}
int Game::getTurnLimit() const {return turnLimit;}
int* Game::getPlayerTurnOrder() const {return playerTurnOrder;}
bool Game::isGameEnded() const {return GameEnded;}
Board Game::getBoard() const {return this->board;}

void Game::setCurrentPlayerIndex(int currentPlayerIndex) {Game::currentPlayerIndex = currentPlayerIndex;}
void Game::setTurnCount(int turnCount) {Game::turnCount = turnCount;}
void Game::setGameEnded(bool gameState) {Game::GameEnded = gameState;}



void Game::newTurn() {
    cout << "Turn " << this->getTurnCount() << endl;
    while (this->getCurrentPlayerIndex() < this->getPlayerCount()-1){
        cout << "Player " << this->getCurrentPlayer()+1 << " turn" << endl;
        this->getBoard().printBoard();
        this->setNextPlayer();
    }
    this->setCurrentPlayerIndex(0);
    this->setTurnCount(this->getTurnCount() + 1);
}

int Game::getCurrentPlayer() {
    return this->getPlayerTurnOrder()[this->getCurrentPlayerIndex()];
}

//region: Private methods

int* Game::randomizePlayerTurnOrder(int playerCount){
    //gets a seed based on the current time for the rand() function
    srand(static_cast<unsigned>(time(nullptr)));

    int* playerTurnOrder = new int[playerCount];
    for (int i = 0; i < playerCount; ++i) playerTurnOrder[i] = i;
    for (int i = 0; i < playerCount; ++i) {
        int randomIndex = rand() % playerCount;
        int temp = playerTurnOrder[i];
        playerTurnOrder[i] = playerTurnOrder[randomIndex];
        playerTurnOrder[randomIndex] = temp;
    }
    return playerTurnOrder;
}

void Game::setNextPlayer() {
    this->setCurrentPlayerIndex((this->getCurrentPlayerIndex() + 1) % this->getPlayerCount());
}