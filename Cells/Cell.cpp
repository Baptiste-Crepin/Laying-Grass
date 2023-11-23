//
// Created by Baptiste Crepin on 03/11/2023.
//

#include "Cell.h"

Cell::Cell(int x, int y, std::string color, CellTypeEnum type) : x(x), y(y), color(color), type(type) {}

Cell::~Cell() {}

int Cell::getX() const { return x; }

int Cell::getY() const { return y; }

CellTypeEnum Cell::getType() const { return type; }

char Cell::getLabel() const {
    return static_cast<char>(type);
}

void Cell::setX(int x) { this->x = x; }

void Cell::setY(int y) { this->y = y; }

void Cell::setType(CellTypeEnum type) { this->type = type; }

const std::string &Cell::getColor() const { return color; }

