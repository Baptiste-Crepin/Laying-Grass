//
// Created by Baptiste Crepin on 03/11/2023.
//

#ifndef LAYINGGRASS_CELL_H
#define LAYINGGRASS_CELL_H


#include "../enums/CellTypeEnum.h"

//A cell represents a 1x1 on the map
class Cell {
private:
    int x;
    int y;
    CellTypeEnum type;

public:
    Cell(int x, int y, CellTypeEnum type = Void);
    ~Cell();

    int getX() const;
    int getY() const;
    CellTypeEnum getType() const;

    void setX(int x);
    void setY(int y);
    void setType(CellTypeEnum type);
};


#endif //LAYINGGRASS_CELL_H
