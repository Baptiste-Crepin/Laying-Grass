//
// Created by Baptiste Crepin on 03/11/2023.
//

#include "Tile.h"
#include <iostream>
#include <fstream>
#include <vector>
#include <filesystem>
#include <string>

using namespace std;

Tile::~Tile() {
//    std::cout << "DELETE TILE" << std::endl;
}

int Tile::getId() const { return id; }

Tile::Tile(int id) : id(id) {}

Tile::Tile(std::string path) : path(path) {}


Tile::Tile() {}

vector<vector<char>> Tile::retreiveTileLayout() {

    string basePath = "../Assets/TilesLayout/";
    if (this->path != "") path = basePath + this->path;
    else path = basePath + "Grass/Grass_" + to_string(this->getId());

    std::filesystem::path AbsolutePath = this->getAbsolutePath(basePath);

    std::ifstream fichier(AbsolutePath);

    if (not fichier) {
        std::cerr << "Erreur : Impossible d'ouvrir le fichier." << std::endl;
        exit(100);
    }
    
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



//private methods:

std::filesystem::path Tile::getAbsolutePath(std::filesystem::path relativePath) {
    std::filesystem::path currentPath = std::filesystem::current_path();
    return currentPath / relativePath;
}