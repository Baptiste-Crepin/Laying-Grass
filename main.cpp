#include <iostream>
#include <cstdlib>
#include <ctime>
#include <string>
#include "Game.h"
#include "Board.h"
#include "fstream"
#include <vector>
#include <string>

using namespace std;

int main() {
    Board board(20);
    std::ifstream fichier("C:\\Users\\martin\\Documents\\SUPINFO\\CPP_eval\\Laying-Grass\\Assets\\TilesLayout\\Grass\\Grass_1");

    if (fichier) {
        std::vector<std::vector<char>> tableau;

        std::string ligne;
        while (std::getline(fichier, ligne)) {
            std::vector<char> ligneTableau;

            for (char c: ligne) {
                if (c == '0' || c == '1') {
                    ligneTableau.push_back(c);
                }
            }

            if (!ligneTableau.empty()) {
                tableau.push_back(ligneTableau);
            }
        }

        fichier.close();

        char t = -2;
        int s, q;
        cout << "Entrez les coordonnées de la case en haut à gauche : " << endl;
        cin >> s;
        cin >> q;

        for (int i = 0; i < tableau.size(); ++i) {
            for (int j = 0; j < tableau[i].size(); ++j) {
                if (tableau[i][j] == '1') {
                    board.setValue(i + s, j + q, t);
                } else {
                    board.setValue(i + s, j + q,'0');
                }

            }
        }

        board.display(); // Supposons que cette fonction imprime l'état actuel du tableau dans votre objet Board
    } else {
        std::cerr << "Erreur : Impossible d'ouvrir le fichier." << std::endl;
    }

    return 0;
}


//char t = -2;
//std::cout << t;
