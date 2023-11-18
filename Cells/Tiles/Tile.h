//
// Created by Baptiste Crepin on 03/11/2023.
//

#ifndef LAYINGGRASS_Piece_H
#define LAYINGGRASS_Piece_H

#include <string>

//The Tile is the base class for all the different Tiles
class Tile {
protected:
    int id;
    //list of relative coordinates
    //type = enum (grass, void, bonus)

public:
//    Tile(int x, int y);
//    ~Tile();
    Tile(int id);

    Tile();

    ~Tile();

    int getId() const;

};


#endif //LAYINGGRASS_Piece_H
