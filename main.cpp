#include <iostream>
#include <cstdlib>
#include <ctime>
#include <string>
#include "Game.h"
#include "Board.h"
#include "Rotate_90.h"
#include "Rotate_n90.h"
#include "Horizontal_symmetry.h"
#include "Vertical_symmetry.h"
#include "fstream"
#include <vector>
#include <string>

using namespace std;

//std::vector<std::vector<char>> retreiveTileLayout() {
//    int tileId = 1;
//    string path =
//            "/Users/baptistecrepin/Desktop/Code/GitHub/Supinfo/projets/LayingGrass/Assets/TilesLayout/Grass/Grass_" +
//            to_string(tileId);
////    string path = "C:\\Users\\martin\\Documents\\SUPINFO\\CPP_eval\\Laying-Grass\\Assets\\TilesLayout\\Grass\\Grass_1";
////    std::ifstream fichier("C:\\Users\\martin\\Documents\\SUPINFO\\CPP_eval\\Laying-Grass\\Assets\\TilesLayout\\Grass\\Grass_1");
//
//    std::ifstream fichier(path);
//
//    if (not fichier) {
//
//        std::cerr << "Erreur : Impossible d'ouvrir le fichier." << std::endl;
//        exit(100);
//    }
//
//    std::cout << "Fichier ouvert !" << std::endl;
//    std::vector<std::vector<char>> tableau;
//
//    std::string ligne;
//    while (std::getline(fichier, ligne)) {
//        std::vector<char> ligneTableau;
//
//        for (char c: ligne) {
//            if (c == '0' || c == '1') {
//                ligneTableau.push_back(c);
//            }
//        }
//
//        if (!ligneTableau.empty()) {
//            tableau.push_back(ligneTableau);
//        }
//    }
//
//    fichier.close();
//    return tableau;
//}

int main() {
    Game game = Game(4);
    while (not game.isGameEnded() and game.getTurnCount() <= game.getTurnLimit()) {
        cout << game.getBoard().getSize() << endl;
        game.newTurn();
    }
//    Board board = game.getBoard();

//    std::vector<std::vector<char>> tableau = retreiveTileLayout();
//    //TEST ROTAION SYMETRIE
//    for (const auto &row: tableau) {
//        for (char val: row) {
//            std::cout << val << " ";
//        }
//        std::cout << std::endl;
//    }
//    tableau = symetrieVerticale(tableau);
//    for (const auto &row: tableau) {
//        for (char val: row) {
//            std::cout << val << " ";
//        }
//        std::cout << std::endl;
//    }
//
//    char t = -2;  // -2 = Grass
//    int x, y;
//    cout << "Entrez les coordonnees de la case en haut a gauche x, y: " << endl;
//    cin >> x;
//    cin >> y;
//
//    for (int i = 0; i < tableau.size(); ++i) {
//        for (int j = 0; j < tableau[i].size(); ++j) {
//            if (tableau[i][j] == '1') {
//                board.setValue(i + x, j + y, t);
//            } else {
//                board.setValue(i + x, j + y, '0');
//            }
//
//        }
//    }
//
//
//    game.getBoard().display();
////    board.display(); // Supposons que cette fonction imprime l'état actuel du tableau dans votre objet Board

    return 0;
}