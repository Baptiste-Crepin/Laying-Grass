//
// Created by Baptiste Crepin on 12/11/2023.
//

#ifndef LAYINGGRASS_GAME_H
#define LAYINGGRASS_GAME_H


#include "Board.h"
#include "Player.h"
#include "Cells/Tiles/Tile.h"
#include "TileQueue.h"
#include <vector>

class Game {
protected:
    const int playerCount;
    int currentPlayerIndex;
    int turnCount = 0;
    const int turnLimit = 9;
    Player *playerTurnOrder;
    bool GameEnded = false;
    Board board;
    TileQueue tileQueue;
    int tileId = 1; // 0 is reserved for the void tile

protected:

    Player *randomizePlayerTurnOrder(int playerCount);

    void setNextPlayer();

    void exchangeLeftoverCoupons();

    bool booleanInput(char acceptChar, char denyChar, std::string message);

    void firstTurn();

    void generateBonuses();

    void handleBonuses(int x, int y);

    bool isValidPlacement(int x, int y, std::vector<std::vector<char>> tableau, bool ignoreTerritory = false);

    void stealCell(Cell Cell);

    void activeRobberyBonus();

public:
    static Game initializeGame();

    Game(int playerCount, int turnLimit = 9);

    int getPlayerCount() const;

    int getCurrentPlayerIndex() const;

    Player &getCurrentPlayer() const;

    int getTurnCount() const;

    int getTurnLimit() const;

    Player *getPlayerTurnOrder() const;

    bool isGameEnded() const;

    const Board getBoard() const;

    void getPlayerInfoFromUser(std::string &playerName, char &playerColor);

    void setGameEnded(bool gameState);

    void setCurrentPlayerIndex(int currentPlayerIndex);

    void setTurnCount(int turnCount);


    void newTurn();

    const TileQueue &getTileQueue() const;

    void setTileQueue(const TileQueue &tileQueue);

    bool askForTileExchangeUse();

    void placeTile(std::string path = "", bool ignoreTerritory = false, CellTypeEnum type = CellTypeEnum::Grass);

    void startGame();

    int getTileId() const;

    void setTileId(int tileId);

};


#endif //LAYINGGRASS_GAME_H
