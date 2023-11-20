//
// Created by Baptiste Crepin on 03/11/2023.
//

#include "Tile.h"
#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

Tile::~Tile() {
//    std::cout << "DELETE TILE" << std::endl;
}

int Tile::getId() const { return id; }

Tile::Tile(int id) : id(id) {}

Tile::Tile() {}

vector<vector<char>> Tile::retreiveTileLayout() {
    int tileId = id;
    string path =
            "/Users/baptistecrepin/Desktop/Code/GitHub/Supinfo/projets/LayingGrass/Assets/TilesLayout/Grass/Grass_" +
            to_string(tileId);
//    string path = "C:\\Users\\martin\\Documents\\SUPINFO\\CPP_eval\\Laying-Grass\\Assets\\TilesLayout\\Grass\\Grass_1";

    std::ifstream fichier(path);

    if (not fichier) {
        std::cerr << "Erreur : Impossible d'ouvrir le fichier." << std::endl;
        exit(100);
    }

    std::cout << "Fichier ouvert !" << std::endl;
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
    return tableau;
}
