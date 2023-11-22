cmake_minimum_required(VERSION 3.24)
project(LayingGrass)

set(CMAKE_CXX_STANDARD 23)

add_executable(LayingGrass main.cpp Cells/Tiles/Tile.cpp Cells/Tiles/Tile.h enums/ColorEnum.h Cells/Cell.cpp Cells/Cell.h enums/CellTypeEnum.h Board.cpp Board.h Cells/Tiles/Tile.h Game.cpp Game.h Player.cpp Player.h
        Rotate_90.cpp
        Rotate_90.h
        Rotate_n90.cpp
        Rotate_n90.h
        Horizontal_symmetry.cpp
        Horizontal_symmetry.h
        Vertical_symmetry.cpp
        Vertical_symmetry.h
        TileQueue.cpp TileQueue.h
        Choice_tiles.cpp
        Choice_tiles.h
        Cells/Tiles/BonusTiles/BonusTile.cpp Cells/Tiles/BonusTiles/BonusTile.h Cells/Tiles/BonusTiles/Stone.cpp Cells/Tiles/BonusTiles/Stone.h Cells/Tiles/BonusTiles/Robbery.cpp Cells/Tiles/BonusTiles/Robbery.h Cells/Tiles/BonusTiles/TileExchange.cpp Cells/Tiles/BonusTiles/TileExchange.h)
