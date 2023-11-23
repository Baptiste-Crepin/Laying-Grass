//
// Created by Baptiste Crepin on 03/11/2023.
//
#ifndef LAYINGGRASS_CELL_H
#define LAYINGGRASS_CELL_H


#include "../enums/CellTypeEnum.h"
#include <string>

//A cell represents a 1x1 on the map

class Cell {
private:
    int tileId;

private:
    int x;
    int y;
    std::string color;
    CellTypeEnum type;
    bool fill;

public:
    Cell() : x(0), y(0), type(Void) {}

    const std::string &getColor() const;

    Cell(int x, int y, std::string color, CellTypeEnum type = Void, int tileId = 0, int fill = 0);

    ~Cell();

    int getX() const;

    int getY() const;

    int getfill() const;

    int setfill(int fill);

    CellTypeEnum getType() const;

    char getLabel() const;

    void setX(int x);

    void setY(int y);

    void setType(CellTypeEnum type);

    int getTileId() const;
};


#endif //LAYINGGRASS_CELL_H
