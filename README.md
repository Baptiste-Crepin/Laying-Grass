# Laying Grass

## Documentation Utilisateur

## 1. Introduction

Bienvenue dans le jeu de plateau "Laying Grass" ! Cette documentation vous guidera à travers les fonctionnalités du jeu,
en mettant l'accent sur l'utilisation de la classe principale, `Game`.

## 2. lancer le programme

- with Clion:
    - ouvrir le projet
    - clique drroit sur le dossier
    - click sur "Reload CMake Project"
    - click sur le bouton "Run" en haut a droite

## 3. Comment Jouer

"Laying Grass" est un jeu de stratégie où les joueurs placent des tuiles pour créer des prairies et gagner des points.
Chaque joueur a la possibilité de remplir des objectifs spécifiques pour maximiser leur score. Le jeu se déroule sur un
plateau, et chaque tour offre de nouvelles opportunités de marquer des points.

## 4. Fonctionnalités Principales

### 4.1 Initialisation du Jeu

Pour commencer une partie, utilisez le constructeur de la classe `Game` en spécifiant le nombre de joueurs et,
optionnellement, le nombre maximal de tours.

```cpp
Game monJeu = Game(playerCount, turnLimit);
```

### 4.2 Démarrer la Partie

Une fois initialisé, lancez la partie avec la méthode startGame().

```cpp
monJeu.startGame();
```

### 4.3 Tour de jeu

Chaque tour de jeu vous avez plusieur choix:

- Placer votre tuile
- Tourner votre tuile de 90 degrés
- Tourner votre tuile symétriquement
- Echanger un ticket pour choisir une autre tuile dans la liste
- Echanger un ticket pour détruire une pierre

### 4.4 But du jeu

Le but du jeu est de marquer le plus de points possible en plaçant des tuiles sur le plateau.
Le joueur avec le plus grand territoire est le gagnant.

Un territoire doit obligatoirement être de forme carrée.

```cli
| Joueur 1 | Joueur 2 | Joueur 3 | Joueur 4 |
| XXXXXX   | X        | XXXXX    | XXX      |
| XXXX     | XXX      | XXXXX    | X X      |
| XXXXXX   | XXXX     | XXXXX    | XXXX     |
| XXXXXX   | XXX      | XXXXX    | X  X     |
| Total: 4 | Total: 3 | Total: 5 | Total: 1 |
```

## 5. Exemple d'uilitisation de la classe Game

```cpp
// Initialisation du jeu avec 2 joueurs et 10 tours max
Game monJeu = Game(2, 10);

// Démarrage de la partie
monJeu.startGame();

// le reste est fait automatiquement. vous n'avez qu'a
// suivre les instructions dans la console.
```



