//
// Created by Baptiste Crepin on 03/11/2023.
//

#include "Tile.h"

//Tile::Tile(int x, int y) : x(x), y(y) {}
//Tile::~Tile() {}
//
//int Tile::getX() const {return x;}
//int Tile::getY() const {return y;}
//
//void Tile::setX(int x) {Tile::x = x;}
//void Tile::setY(int y) {Tile::y = y;}

Tile::Tile(int id) : id(id) {}

Tile::Tile() {}

Tile::~Tile() {}

int Tile::getId() const { return id; }

