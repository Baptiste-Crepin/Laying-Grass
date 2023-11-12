//
// Created by Baptiste Crepin on 12/11/2023.
//

#ifndef LAYINGGRASS_GAME_H
#define LAYINGGRASS_GAME_H


#include "Board.h"

class Game {
private:
    const int playerCount; // TODO: min 2, max 9
    int currentPlayerIndex;
    int turnCount = 0;
    const int turnLimit = 9;
    int* playerTurnOrder;
    bool isGameFinished = false;
    Board board;

//public:
    int* randomizePlayerTurnOrder(int playerCount);

public:
    Game(int playerCount, int turnLimit = 9);

    int getPlayerCount() const;
    int getCurrentPlayerIndex() const;
    int getTurnCount() const;
    int getTurnLimit() const;
    int *getPlayerTurnOrder() const;
    bool isGameFinished1() const;
    Board getBoard() const;

    void setIsGameFinished(bool isGameFinished);
    void setCurrentPlayerIndex(int currentPlayerIndex);
    void setTurnCount(int turnCount);
};


#endif //LAYINGGRASS_GAME_H
