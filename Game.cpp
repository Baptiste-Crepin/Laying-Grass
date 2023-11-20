//
// Created by Baptiste Crepin on 12/11/2023.
//

#include <iostream>
#include <cstdlib>
#include <ctime>
#include <string>
#include "Game.h"
#include <vector>

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

const Board Game::getBoard() const { return board; }


void Game::setCurrentPlayerIndex(int currentPlayerIndex) { Game::currentPlayerIndex = currentPlayerIndex; }

void Game::setTurnCount(int turnCount) { Game::turnCount = turnCount; }

void Game::setGameEnded(bool gameState) { Game::GameEnded = gameState; }

void Game::newTurn() {
    cout << "Turn " << this->getTurnCount() << endl;


    do {
        this->getBoard().display();

        cout << "Player " << this->getCurrentPlayerIndex() + 1 << " | " << endl;
        cout << "Queue : " << endl;
        this->getTileQueue().displayQueue();

        if (askForTileExchangeUse()) {
            this->getCurrentPlayer().setExchangeTickets(this->getCurrentPlayer().getExchangeTickets() - 1);
            tileQueue.tileExchange();

        }
        this->placeTile();
        tileQueue.nextTile();


        this->setNextPlayer();

    } while ((this->getCurrentPlayerIndex() < this->getPlayerCount()));

    this->setTurnCount(this->getTurnCount() + 1);
}

const TileQueue &Game::getTileQueue() const {
    return tileQueue;
}

void Game::setTileQueue(const TileQueue &tileQueue) {
    Game::tileQueue = tileQueue;
}

Player &Game::getCurrentPlayer() const {
    return this->getPlayerTurnOrder()[this->getCurrentPlayerIndex()];
}

//region: Private methods

Player *Game::randomizePlayerTurnOrder(int playerCount) {
    //gets a seed based on the current time for the rand() function
    srand(static_cast<unsigned>(time(nullptr)));

    Player *playerTurnOrder = new Player[playerCount];
//    string name = "Test"; // Todo: get this a variable from the player
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
    this->setCurrentPlayerIndex((this->getCurrentPlayerIndex() + 1) % (this->getPlayerCount()));
}


bool Game::askForTileExchangeUse() {
    int currentExchangeTickets = this->getCurrentPlayer().getExchangeTickets();
    if (currentExchangeTickets < 1) {
        cout << "You don't have any exchange ticket left, you can't exchange this turn.";
        return false;
    }

    char input;
    do {
        cout << "You have " << currentExchangeTickets << " ticket(s), do you want to exchange ? (y/n)";
        cin >> input;
    } while (input != 'y' && input != 'n');

    return input == 'y';
}


bool Game::placeTile() {
    Tile tile = this->getTileQueue().getCurrentTile();
    vector<vector<char>> tableau = tile.retreiveTileLayout();

    char t = -2;  // -2 = Grass
    int x, y;
    cout << "Entrez les coordonnees de la case en haut a gauche x, y: " << endl;
    cin >> x;
    cin >> y;

    for (int i = 0; i < tableau.size(); ++i) {
        for (int j = 0; j < tableau[i].size(); ++j) {
            if (tableau[i][j] == '1') {
                board.setValue(i + x, j + y, t);
            } else {
                board.setValue(i + x, j + y, '0');
            }

        }
    }

    return true; //todo: return false if the tile can't be placed at the specified coordinates
}

