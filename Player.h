//
// Created by Baptiste Crepin on 17/11/2023.
//

#ifndef LAYINGGRASS_PLAYER_H
#define LAYINGGRASS_PLAYER_H

#include <string>

class Player {
private:
    int id;
    std::string name;

public:
    Player(int id, std::string name);
    Player();
    ~Player();

    int getId() const;
    const std::string &getName() const;
};


#endif //LAYINGGRASS_PLAYER_H
