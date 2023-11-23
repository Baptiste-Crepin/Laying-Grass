//
// Created by Baptiste Crepin on 03/11/2023.
//

#include "Cell.h"

Cell::Cell(int x, int y, std::string color, CellTypeEnum type, int tileId, int fill) : x(x), y(y), color(color), type(type),
                                                                             tileId(tileId), fill(fill) {
}

Cell::~Cell() {}

int Cell::getX() const { return x; }

int Cell::getY() const { return y; }

int Cell::getfill() const { return fill; }

CellTypeEnum Cell::getType() const { return type; }

char Cell::getLabel() const {
    return static_cast<char>(type);
}

int Cell::setfill(int fill){this->fill = fill;}

void Cell::setX(int x) { this->x = x; }

void Cell::setY(int y) { this->y = y; }

void Cell::setType(CellTypeEnum type) { this->type = type; }

const std::string &Cell::getColor() const { return color; }

int Cell::getTileId() const { return tileId; }

