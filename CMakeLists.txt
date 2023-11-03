cmake_minimum_required(VERSION 3.24)
project(LayingGrass)

set(CMAKE_CXX_STANDARD 23)

add_executable(LayingGrass main.cpp Cells/Tiles/Tile.cpp Cells/Tiles/Tile.h enums/ColorEnum.h Cells/Cell.cpp Cells/Cell.h enums/CellTypeEnum.h)
