//
// Created by Baptiste Crepin on 12/11/2023.
//

#ifndef LAYINGGRASS_GAME_H
#define LAYINGGRASS_GAME_H


#include "Board.h"
#include "Player.h"
#include "Cells/Tiles/Tile.h"
#include "TileQueue.h"

class Game {
private:
    const int playerCount; // TODO: min 2, max 9
    int currentPlayerIndex;
    int turnCount = 0;
    const int turnLimit = 9;
    Player *playerTurnOrder;
    bool GameEnded = false;
    Board board;
    TileQueue tileQueue;

private:

    Player *randomizePlayerTurnOrder(int playerCount);

    void setNextPlayer();

public:
    Game(int playerCount, int turnLimit = 9);

    int getPlayerCount() const;

    int getCurrentPlayerIndex() const;

    Player &getCurrentPlayer() const;

    int getTurnCount() const;

    int getTurnLimit() const;

    Player *getPlayerTurnOrder() const;

    bool isGameEnded() const;

    const Board getBoard() const;


    void setGameEnded(bool gameState);

    void setCurrentPlayerIndex(int currentPlayerIndex);

    void setTurnCount(int turnCount);


    void newTurn();

    const TileQueue &getTileQueue() const;

    void setTileQueue(const TileQueue &tileQueue);

    bool askForTileExchangeUse();

    bool placeTile(std::string path = "");

    void startGame();

};


#endif //LAYINGGRASS_GAME_H
