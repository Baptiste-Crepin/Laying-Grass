//
// Created by Baptiste Crepin on 03/11/2023.
//

#ifndef LAYINGGRASS_Piece_H
#define LAYINGGRASS_Piece_H

#include <string>
#include <vector>
#include <filesystem>

//The Tile is the base class for all the different Tiles
class Tile {
protected:
    int id;
    std::string path;

    std::filesystem::path getAbsolutePath(std::filesystem::path relativePath);

public:
    ~Tile();

    Tile(int id);

    Tile(std::string path);

    Tile();

    int getId() const;

    std::vector<std::vector<char>> retreiveTileLayout();
};


#endif //LAYINGGRASS_Piece_H
