cmake_minimum_required(VERSION 3.24)
project(LayingGrass)

set(CMAKE_CXX_STANDARD 23)

add_executable(LayingGrass main.cpp Cells/Tiles/Tile.cpp Cells/Tiles/Tile.h enums/ColorEnum.h Cells/Cell.cpp Cells/Cell.h enums/CellTypeEnum.h Board.cpp Board.h Cells/Tiles/Tile.h Game.cpp Game.h Player.cpp Player.h
        Placement/Rotate_90.cpp
        Placement/Rotate_90.h
        Placement/Rotate_n90.cpp
        Placement/Rotate_n90.h
        Placement/Horizontal_symmetry.cpp
        Placement/Horizontal_symmetry.h
        Placement/Vertical_symmetry.cpp
        Placement/Vertical_symmetry.h
        TileQueue.cpp TileQueue.h
        Placement/Choice_tiles.cpp
        Placement/Choice_tiles.h
        Cells/Tiles/BonusTiles/BonusTile.cpp Cells/Tiles/BonusTiles/BonusTile.h Cells/Tiles/BonusTiles/Stone.cpp Cells/Tiles/BonusTiles/Stone.h Cells/Tiles/BonusTiles/Robbery.cpp Cells/Tiles/BonusTiles/Robbery.h Cells/Tiles/BonusTiles/TileExchange.cpp Cells/Tiles/BonusTiles/TileExchange.h)
