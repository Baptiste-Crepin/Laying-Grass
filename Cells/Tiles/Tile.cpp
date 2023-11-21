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

Tile::Tile(std::string path) : path(path) {}


Tile::Tile() {}

vector<vector<char>> Tile::retreiveTileLayout() {
//    int tileId = id;
//    cout << "Tile id : " << tileId << endl;
//    string path =
//            "/Users/baptistecrepin/Desktop/Code/GitHub/Supinfo/projets/LayingGrass/Assets/TilesLayout/Grass/Grass_" +
//            to_string(tileId);
////    string path = "C:\\Users\\martin\\Documents\\SUPINFO\\CPP_eval\\Laying-Grass\\Assets\\TilesLayout\\Grass\\Grass_0";

//    string basePath = "C:\\Users\\martin\\Documents\\SUPINFO\\CPP_eval\\Laying-Grass\\Assets\\TilesLayout\\Grass\\Grass_";
    string basePath = "/Users/baptistecrepin/Desktop/Code/GitHub/Supinfo/projets/LayingGrass/Assets/TilesLayout/";
    string path;

    if (this->path != "") path = basePath + this->path;
    else path = basePath + "Grass/Grass_" + to_string(this->getId());

    cout << path << endl;
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
