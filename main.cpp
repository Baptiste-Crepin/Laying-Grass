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

int main() {
    Game game = Game(4);
    while (not game.isGameEnded() and game.getTurnCount() <= game.getTurnLimit()) {
        cout << game.getBoard().getSize() << endl;
        game.newTurn();
    }

//    Board board(20);
//    string path = "/Users/baptistecrepin/Desktop/Code/GitHub/Supinfo/projets/LayingGrass/Assets/TilesLayout/Grass/Grass_1";
////    string path = "C:\\Users\\martin\\Documents\\SUPINFO\\CPP_eval\\Laying-Grass\\Assets\\TilesLayout\\Grass\\Grass_1";
////    std::ifstream fichier("C:\\Users\\martin\\Documents\\SUPINFO\\CPP_eval\\Laying-Grass\\Assets\\TilesLayout\\Grass\\Grass_1");
//
//    std::ifstream fichier(path);
//
//    if (fichier) {
//        std::cout << "Fichier ouvert !" << std::endl;
//        std::vector<std::vector<char>> tableau;
//
//        std::string ligne;
//        while (std::getline(fichier, ligne)) {
//            std::vector<char> ligneTableau;
//
//            for (char c: ligne) {
//                if (c == '0' || c == '1') {
//                    ligneTableau.push_back(c);
//                }
//            }
//
//            if (!ligneTableau.empty()) {
//                tableau.push_back(ligneTableau);
//            }
//        }
//
//        fichier.close();
//
//        //TEST ROTAION SYMETRIE
//        for (const auto &row: tableau) {
//            for (char val: row) {
//                std::cout << val << " ";
//            }
//            std::cout << std::endl;
//        }
//        tableau = symetrieVerticale(tableau);
//        for (const auto &row: tableau) {
//            for (char val: row) {
//                std::cout << val << " ";
//            }
//            std::cout << std::endl;
//        }
//
//        char t = -2;  // -2 = Grass
//        int s, q;
//        cout << "Entrez les coordonnees de la case en haut a gauche x, y: " << endl;
//        cin >> s;
//        cin >> q;
//
//        for (int i = 0; i < tableau.size(); ++i) {
//            for (int j = 0; j < tableau[i].size(); ++j) {
//                if (tableau[i][j] == '1') {
//                    board.setValue(i + s, j + q, t);
//                } else {
//                    board.setValue(i + s, j + q, '0');
//                }
//
//            }
//        }
//
//        board.display(); // Supposons que cette fonction imprime l'état actuel du tableau dans votre objet Board
//    } else {
//        std::cerr << "Erreur : Impossible d'ouvrir le fichier." << std::endl;
//    }

    return 0;
}
