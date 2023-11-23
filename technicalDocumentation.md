# Documentation Technique de la Classe Game

## 1. Introduction

Ce document offre une documentation technique pour la classe `Game` du jeu de plateau "Laying Grass". La classe gère
l'état du jeu, les tours des joueurs, le plateau et la logique du jeu.

## 2. Aperçu de la Classe

La classe `Game` représente la fonctionnalité principale du jeu de plateau. Elle inclut des méthodes pour initialiser le
jeu, gérer les tours des joueurs, placer des tuiles et vérifier les conditions de fin de partie.

## 3. Attributs

- `playerCount`: Nombre de joueurs dans le jeu.
- `currentPlayerIndex`: Index du joueur actuel.
- `turnCount`: Nombre de tours écoulés.
- `turnLimit`: Nombre maximal de tours autorisés.
- `playerTurnOrder`: Tableau des joueurs indiquant l'ordre des tours.
- `GameEnded`: Indique si le jeu est terminé.
- `board`: Instance de la classe `Board` représentant le plateau de jeu.
- `tileQueue`: Instance de la classe `TileQueue` gérant la file des tuiles.

## 4. Constructeur

### `Game(int playerCount, int turnLimit = 9);`

- **Paramètres:**
    - `playerCount`: Nombre de joueurs dans le jeu.
    - `turnLimit`: Nombre maximal de tours autorisés.

## 5. Méthodes Publiques

### Accesseurs:

- `getPlayerCount() const`
- `getCurrentPlayerIndex() const`
- `getCurrentPlayer() const`
- `getTurnCount() const`
- `getTurnLimit() const`
- `getPlayerTurnOrder() const`
- `isGameEnded() const`
- `getBoard() const`
- `getTileQueue() const`

### Mutateurs:

- `setGameEnded(bool gameState)`
- `setCurrentPlayerIndex(int currentPlayerIndex)`
- `setTurnCount(int turnCount)`
- `setTileQueue(const TileQueue &tileQueue)`

### Cycle de Vie du Jeu:

- `initializeGame()`
- `startGame()`
- `newTurn()`

### Logique du Jeu:

- `askForTileExchangeUse()`
- `placeTile(std::string path = "", bool ignoreTerritory = false, CellTypeEnum type = CellTypeEnum::Grass)`

## 6. Méthodes Protégées

- `randomizePlayerTurnOrder(int playerCount)`
- `setNextPlayer()`
- `exchangeLeftoverCoupons()`
- `booleanInput(char acceptChar, char denyChar, std::string message)`
- `firstTurn()`
- `generateBonuses()`
- `handleBonuses(int x, int y)`
- `isValidPlacement(int x, int y, std::vector<std::vector<char>> tableau)`

## 7. Méthodes Statiques

- `initializeGame()`

## 8. Exemples d'Utilisation

```cpp
// Exemple d'utilisation de la classe Game
Game monJeu = Game::initializeGame();
monJeu.startGame();
