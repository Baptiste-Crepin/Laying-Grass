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
#include "Cells/Cell.h"
#include "Placement/Choice_tiles.h"

#define RESET   "\033[0m"
#define RED     "\033[31m"
#define GREEN   "\033[32m"
#define YELLOW  "\033[33m"
#define BLUE    "\033[34m"
#define MAGENTA "\033[35m"
#define CYAN    "\033[36m"

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

const Board Game::getBoard() const { return board; }

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

        if (this->getBoard().inBoard(CellTypeEnum::Stone_Tile)) {
            cout << "There are stones on the board" << endl;
            bool removeStone = this->booleanInput('y',
                                                  'n',
                                                  "Do you wish to destroy one for one exchange ticket");
            if (removeStone) {
                this->getCurrentPlayer().setExchangeTickets(this->getCurrentPlayer().getExchangeTickets() - 1);
                this->getBoard().removeStone();
                this->getBoard().display();
                this->getCurrentPlayer().getExchangeTickets();
                this->getTileQueue().displayQueue();
            }

        }

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

bool verif_color(char color) {
    if (color == 'r' || color == 'g' || color == 'b' || color == 'y' || color == 'p' || color == 'o') {
        return true;
    } else {
        return false;
    }
}

void print_all_players(Player *playerTurnOrder, int playerCount) {
    for (int i = 0; i < playerCount; i++) {
        switch (playerTurnOrder[i].getColor()[0]) {
            case 'r':
                cout << RED << " " << playerTurnOrder[i].getName() << " "
                     << playerTurnOrder[i].getColor() << RESET << endl;
                break;
            case 'g':
                cout << GREEN << " " << playerTurnOrder[i].getName() << " "
                     << playerTurnOrder[i].getColor() << RESET << endl;
                break;
            case 'b':
                cout << BLUE << " " << playerTurnOrder[i].getName() << " "
                     << playerTurnOrder[i].getColor() << RESET << endl;
                break;
            case 'y':
                cout << YELLOW << " " << playerTurnOrder[i].getName() << " "
                     << playerTurnOrder[i].getColor() << RESET << endl;
                break;
            case 'p':
                cout << MAGENTA << " " << playerTurnOrder[i].getName() << " "
                     << playerTurnOrder[i].getColor() << RESET << endl;
                break;
            case 'o':
                cout << CYAN << " " << playerTurnOrder[i].getName() << " "
                     << playerTurnOrder[i].getColor() << RESET << endl;
                break;
            default:
                break;

        }
    }
}

Player *Game::randomizePlayerTurnOrder(int playerCount) {
    //gets a seed based on the current time for the rand() function
    srand(static_cast<unsigned>(time(nullptr)));

    Player *playerTurnOrder = new Player[playerCount];  //todo: MODIF POUR TEST [playerCount- 1]; de base
    for (int i = 0; i < playerCount; i++) {
        cout << i << endl;
        cout << "Player " << i + 1 << " Choose your name" << endl;
        std::string name;
        cin >> name;
        std::string color;
        while (!verif_color(color[0])) {
            cout << "Player " << i + 1 << " choose color between r, g, b, y, p, o" << endl;
            cin >> color;
        }
        playerTurnOrder[i] = Player(i, name, color);
    }

    print_all_players(playerTurnOrder, playerCount);

    cout << "Randomizing player turn order..." << endl;
    for (int i = 0; i < playerCount - 1; i++) {
        int randomIndex = rand() % (playerCount - 1);
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
        cout << "You don't have any exchange ticket left, you can't exchange this turn." << endl;
        return false;
    }

    std::string message = "You have " + to_string(currentExchangeTickets) + " ticket(s), do you want to exchange ?";
    return booleanInput('y', 'n', message);
}

void Game::placeTile(std::string path, bool ignoreTerritory, CellTypeEnum type) {

    // if a path is specified, open it, else open the current tile
    Tile tile = path == "" ? this->getTileQueue().getCurrentTile() : Tile(path);
    vector<vector<char>> tileLayout = tile.retreiveTileLayout();
    if (tileLayout.size() > 1 || tileLayout[0].size() > 1) tileLayout = choice_tiles(tileLayout);

    int x, y;
    bool placeable = true;
    do {
        cout << "Please enter valid coordinates for the tile (top left) x, y:" << endl;
        cin >> x;
        cin >> y;
        placeable = isValidPlacement(x, y, tileLayout, ignoreTerritory);
    } while (not placeable);


    for (int i = 0; i < tileLayout.size(); ++i) {
        for (int j = 0; j < tileLayout[i].size(); ++j) {
            if (not(tileLayout[i][j] == '1')) continue;

            board.setValue(i + x, j + y,
                           Cell(i + x, j + y, this->getCurrentPlayer().getColor(), type, this->getTileId()));
            handleBonuses(i + x, j + y);

        }
    }
    this->setTileId(this->getTileId() + 1);
}

void Game::firstTurn() {
    do {
        cout << "Player " << this->getCurrentPlayerIndex() << " | " << this->getPlayerCount() << endl;

        this->getBoard().display();
        placeTile("StartingTiles/start_0", true);
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
            this->placeTile(endTilePath, true);
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
    BonusTile *bonusTiles[3] = {new Stone(), new Robbery(), new TileExchange()};

    for (auto &bonusTile: bonusTiles) {
        double generatedBonuses = 0;

        while (generatedBonuses < this->getPlayerCount() * bonusTile->getTilesPerPlayer()) {
            bool placed = false;

            do {
                int randomX = (rand() % (this->getBoard().getSize() - 2)) + 1;
                int randomY = (rand() % (this->getBoard().getSize() - 2)) + 1;
                if (this->getBoard().getValue(randomX, randomY).getType() == CellTypeEnum::Void) {
                    Cell cell = Cell(randomX, randomY, "b", bonusTile->getType());
                    this->getBoard().setValue(randomX, randomY, cell);
                    placed = true;
                }
            } while (not placed);

            generatedBonuses += 1;
        }
    }
    //todo: delete this test tile
    Cell cell = Cell(0, 0, "b", CellTypeEnum::Bonus_Robbery);
    this->getBoard().setValue(0, 0, cell);
}

void Game::handleBonuses(int x, int y) {
    vector<Cell> neighbors = this->getBoard().getAdjacentNeighbors(x, y);
    for (auto &neighbor: neighbors) {
//        cout << neighbor.getX() << " " << neighbor.getY() << " " << neighbor.getLabel() << endl;
        if (neighbor.getType() != CellTypeEnum::Void && neighbor.getType() != CellTypeEnum::Grass) {

            vector<Cell> bonusNeighbor = this->getBoard().getAdjacentNeighbors(neighbor.getX(), neighbor.getY());
            bool voidNeighbor = false;
            for (auto &c: bonusNeighbor) if (c.getType() == CellTypeEnum::Void) voidNeighbor = true;


            if (not voidNeighbor) {
                switch (neighbor.getType()) {
                    case CellTypeEnum::Bonus_Stone:
                        this->placeTile("Bonuses/Stone_0", true, CellTypeEnum::Stone_Tile);
                        break;
                    case CellTypeEnum::Bonus_Robbery:
                        this->activeRobberyBonus();
                        break;
                    case CellTypeEnum::Bonus_Exchange:
                        TileExchange::applyBonus(this->getCurrentPlayer());
                        break;
                    default:
                        break;
                }

                //replaces the bonus tile with a grass tile
                Cell cell = Cell(neighbor.getX(), neighbor.getY(), "b", CellTypeEnum::Grass);
                this->getBoard().setValue(neighbor.getX(), neighbor.getY(), cell);
            }
        }

    }
}


bool Game::isValidPlacement(int x, int y, vector<vector<char>> tableau, bool ignoreTerritory) {
    bool nextToOwnTerritory = false;

    //placeable if the tile is placed on non grass or stone cell
    for (int i = 0; i < tableau.size(); ++i) {
        for (int j = 0; j < tableau[i].size(); ++j) {
            CellTypeEnum cellType = this->getBoard().getValue(i + x, j + y).getType();
            if (tableau[i][j] == '1' && cellType == CellTypeEnum::Grass || cellType == CellTypeEnum::Stone_Tile) {
                cout << "You cannot place a tile on a Grass or Stone " << endl;
                cout << "Cell type : " << i + x << ' ' << j + y << endl;
                return false;
            }

            if (ignoreTerritory == false) {

                //placeable if the tile is placed on a cell that has at least one adjacent neighbor part of the same territory
                vector<Cell> neighbors = this->getBoard().getAdjacentNeighbors(i + x, j + y);
                for (auto &neighbor: neighbors) {
                    if (tableau[i][j] == '0') continue;
                    if (this->getCurrentPlayer().getColor() == neighbor.getColor()) {
                        nextToOwnTerritory = true;
                    } else if (this->getCurrentPlayer().getColor() != neighbor.getColor() &&
                               neighbor.getType() == CellTypeEnum::Grass) {
                        cout << "Invalid Territory placement " << neighbor.getColor() << " "
                             << this->getCurrentPlayer().getColor() << endl;
                        return false;
                    }
                }
            }
        }
    }

    return ignoreTerritory ? true : nextToOwnTerritory;
//    return nextToOwnTerritory;
}

int Game::getTileId() const { return tileId; }

void Game::setTileId(int tileId) { Game::tileId = tileId; }

void Game::stealCell(Cell cell) {
    int Id = cell.getTileId();
    string color = cell.getColor();
    Cell stolenCell = Cell(cell.getX(), cell.getY(), this->getCurrentPlayer().getColor(), CellTypeEnum::Grass);
    this->getBoard().setValue(cell.getX(), cell.getY(), stolenCell);

    vector<Cell> neighbors = this->getBoard().getAdjacentNeighbors(cell.getX(), cell.getY());
    for (auto &neighbor: neighbors) {
        if (neighbor.getTileId() == Id && neighbor.getColor() == color) this->stealCell(neighbor);

    }
}

void Game::activeRobberyBonus() {
    cout << "Enter the coordinates of the tile you want to steal" << endl;
    bool valid = false;
    do {
        int x, y;
        cin >> x >> y;
        Cell chosenCell = this->getBoard().getValue(x, y);
        if (chosenCell.getType() == CellTypeEnum::Grass &&
            chosenCell.getColor() != this->getCurrentPlayer().getColor()) {
            this->stealCell(chosenCell);
            valid = true;
        } else {
            cout << "Invalid cell" << endl;
        }
    } while (not valid);
}

//endregion