//
// Created by Baptiste Crepin on 12/11/2023.
//

#include <iostream>
#include <cstdlib>
#include <ctime>
#include <string>
#include "Game.h"
#include <vector>
#include "Cells/Tiles/BonusTiles/BonusTile.h"
#include "Cells/Tiles/BonusTiles/Stone.h"
#include "Cells/Tiles/BonusTiles/Robbery.h"
#include "Cells/Tiles/BonusTiles/TileExchange.h"

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

//region: Getters and Setters
int Game::getPlayerCount() const { return playerCount; }

int Game::getCurrentPlayerIndex() const { return currentPlayerIndex; }

int Game::getTurnCount() const { return turnCount; }

int Game::getTurnLimit() const { return turnLimit; }

Player *Game::getPlayerTurnOrder() const { return playerTurnOrder; }

bool Game::isGameEnded() const { return GameEnded; }

void Game::setCurrentPlayerIndex(int currentPlayerIndex) { Game::currentPlayerIndex = currentPlayerIndex; }

void Game::setTurnCount(int turnCount) { Game::turnCount = turnCount; }

void Game::setGameEnded(bool gameState) { Game::GameEnded = gameState; }

const TileQueue &Game::getTileQueue() const { return tileQueue; }

void Game::setTileQueue(const TileQueue &tileQueue) { Game::tileQueue = tileQueue; }

//endregion

//region: Public methods

void Game::newTurn() {
    do {
        this->getBoard().display();
        cout << "Turn " << this->getTurnCount() << endl;
        cout << "Player " << this->getCurrentPlayerIndex() + 1 << " | " << this->getCurrentPlayer().getId() << endl;
        cout << "Queue : " << endl;

        this->getTileQueue().displayQueue();

        if (askForTileExchangeUse()) {
            this->getCurrentPlayer().setExchangeTickets(this->getCurrentPlayer().getExchangeTickets() - 1);
            tileQueue.tileExchange();
        }

        this->placeTile();
        tileQueue.nextTile();
        this->setNextPlayer();

    } while (this->getCurrentPlayerIndex() > 0);

    this->setTurnCount(this->getTurnCount() + 1);
}


Player &Game::getCurrentPlayer() const { return this->getPlayerTurnOrder()[this->getCurrentPlayerIndex()]; }

void Game::startGame() {

    //first turn
    this->firstTurn();

    //main loop
    while (not this->isGameEnded() and this->getTurnCount() <= this->getTurnLimit()) {
        this->newTurn();
    }

    //end game
    this->exchangeLeftoverCoupons();
}

//endregion

//region: Static methods

Game Game::initializeGame() {
    cout << "Welcome to Laying Grass" << endl;
    cout << "How many players are there ?" << endl;
    int playerCount;
    do {
        cout << "Please enter a number between 2 and 9" << endl;
        cin >> playerCount;
    } while (playerCount < 2 || playerCount > 9);
    Game game = Game(playerCount);
    game.generateBonuses();
    return game;
}

// endregion

//region: Private methods

Player *Game::randomizePlayerTurnOrder(int playerCount) {
    //gets a seed based on the current time for the rand() function
    srand(static_cast<unsigned>(time(nullptr)));

    Player *playerTurnOrder = new Player[playerCount - 1];
//    string name = "Test"; // Todo: get this a variable from the player
    for (int i = 0; i < playerCount; i++) playerTurnOrder[i] = Player(i);
    for (int i = 0; i < playerCount; i++) {
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

    std::string message = "You have " + to_string(currentExchangeTickets) + " ticket(s), do you want to exchange ?";
    return booleanInput('y', 'n', message);
}

bool Game::placeTile(std::string path) {
    cout << "Place tile" << endl;
    // if a path is specified, open it, else open the current tile
    Tile tile = path == "" ? this->getTileQueue().getCurrentTile() : Tile(path);
    vector<vector<char>> tableau = tile.retreiveTileLayout();

    int x, y;
    cout << "Entrez les coordonnees de la case en haut a gauche x, y: " << endl;
    cin >> x;
    cin >> y;

    cout << "x: " << x << " y: " << y << endl;
    for (int i = 0; i < tableau.size(); ++i) {
        for (int j = 0; j < tableau[i].size(); ++j) {
            if (tableau[i][j] == '1') {
                cout << "Cell placed  " << i + x << " " << j + y << endl;
                //a cell is placed at the specified coordinates
                //todo: check if the tile can be placed at the specified coordinates

                cout << "Cell placed at " << i + x << " " << j + y << endl;
                board.setValue(i + x, j + y, std::make_shared<Cell>(i + x, j + y, CellTypeEnum::Grass));

                vector<shared_ptr<Cell>> neighbors = this->getBoard().getAdjacentNeighbors(i + x, j + y);
                for (auto &neighbor: neighbors) {
                    cout << neighbor->getX() << " " << neighbor->getY() << " " << neighbor->getLabel() << endl;
                    if (neighbor->getType() != CellTypeEnum::Void && neighbor->getType() != CellTypeEnum::Grass) {

                        vector<shared_ptr<Cell>> t = this->getBoard().getAdjacentNeighbors(neighbor->getX(),
                                                                                           neighbor->getY());
                        cout << "Neighbors of the neighbor" << endl;
                        bool voidNeighbor = false;
                        for (auto &n: t) {
                            if (n->getType() == CellTypeEnum::Void) voidNeighbor = true;
                        }

                        if (not voidNeighbor) {
                            cout << "ACTIVATED" << endl;
                            Board b = this->getBoard();
                            shared_ptr<Cell> c = b.getValue(0, 0);
                            c->applyBonus(this->getCurrentPlayer());
                            cout << "ACTIVATED" << endl;
                            Cell cell = Cell(neighbor->getX(), neighbor->getY(), CellTypeEnum::Grass);
                            b.setValue(neighbor->getX(), neighbor->getY(), std::make_shared<Cell>(cell));
                            this->setBoard(b);

                        }
                    }

                }

            }
        }

        return true; //todo: return false if the tile can't be placed at the specified coordinates
    }
}

void Game::firstTurn() {
    do {
        cout << "Player " << this->getCurrentPlayerIndex() << " | " << this->getPlayerCount() << endl;

        this->getBoard().display();
        placeTile("StartingTiles/start_0");
        this->setNextPlayer();
    } while (this->getCurrentPlayerIndex() > 0);
}

void Game::exchangeLeftoverCoupons() {
    do {
        while (this->getCurrentPlayer().getExchangeTickets() > 0) {

            this->getBoard().display();
            cout << "Player " << this->getCurrentPlayerIndex() << " | " << "You still have "
                 << this->getCurrentPlayer().getExchangeTickets() << " exchange tickets left."
                 << endl;

            string message = "Do you want to exchange them ?";
            if (not booleanInput('y', 'n', message)) break;

            string endTilePath = "EndTiles/coupon";
            this->placeTile(endTilePath);
            this->getCurrentPlayer().setExchangeTickets(this->getCurrentPlayer().getExchangeTickets() - 1);
        }
        this->setNextPlayer();
    } while (this->getCurrentPlayerIndex() > 0);
};


bool Game::booleanInput(char acceptChar, char denyChar, std::string message) {
    char input;
    do {
        cout << message << " (" << acceptChar << "/" << denyChar << ")" << endl;
        cin >> input;
    } while (input != acceptChar && input != denyChar);

    return input == acceptChar;
}

void Game::generateBonuses() {
    cout << "Generating bonuses" << endl;
    BonusTile *bonusTiles[3] = {new Stone(), new Robbery(), new TileExchange()};

    for (auto &bonusTile: bonusTiles) {
        double generatedBonuses = 0;
        while (generatedBonuses < this->getPlayerCount() * bonusTile->getTilesPerPlayer()) {
            bool placed = false;

            do {
                int randomX = (rand() % (this->getBoard().getSize() - 2)) + 1;
                int randomY = (rand() % (this->getBoard().getSize() - 2)) + 1;
                if (this->getBoard().getValue(randomX, randomY)->getType() == CellTypeEnum::Void) {
//                    BonusTile cell = BonusTile(bonusTile->getType(), randomX, randomY);
//                    Board board = this->getBoard();
//                    board.setValue(randomX, randomY, cell);
                    BonusTile cell = BonusTile(bonusTile->getType(), randomX, randomY);
                    Board board = this->getBoard();
                    board.setValue(randomX, randomY, std::make_shared<BonusTile>(cell));
                    this->setBoard(board);
                    placed = true;
                }
            } while (not placed);

            generatedBonuses += 1;
        }
    }

    TileExchange cell = TileExchange();
    board.setValue(0, 0, std::make_shared<TileExchange>(cell));
    this->setBoard(board);
}

void Game::setBoard(const Board &board) {
    Game::board = board;
}

const Board &Game::getBoard() const {
    return board;
}

//endregion