//
// Created by Baptiste Crepin on 12/11/2023.
//

#include <cstdlib>
#include <ctime>
#include "Game.h"

Game::Game(int playerCount, int turnLimit) :
    playerCount(playerCount),
    turnLimit(turnLimit),
    currentPlayerIndex(0),
    turnCount(0),
    isGameFinished(false),
    playerTurnOrder(Game::randomizePlayerTurnOrder(playerCount)),
    board(Board(playerCount < 5 ? 20: 30))
    {}


int Game::getPlayerCount() const {return playerCount;}
int Game::getCurrentPlayerIndex() const {return currentPlayerIndex;}
int Game::getTurnCount() const {return turnCount;}
int Game::getTurnLimit() const {return turnLimit;}
int *Game::getPlayerTurnOrder() const {return playerTurnOrder;}
bool Game::isGameFinished1() const {return isGameFinished;}
Board Game::getBoard() const {return board;}

void Game::setCurrentPlayerIndex(int currentPlayerIndex) {Game::currentPlayerIndex = currentPlayerIndex;}
void Game::setTurnCount(int turnCount) {Game::turnCount = turnCount;}
void Game::setIsGameFinished(bool isGameFinished) {Game::isGameFinished = isGameFinished;}



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