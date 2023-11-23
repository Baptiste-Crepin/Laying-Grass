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
    std::string color;
    int exchangeTickets = 1;

public:
    Player(int id, std::string name, std::string color);

    Player();

    ~Player();

    int getId() const;

    std::string getColor() const;

    std::string getName() const;

    int getExchangeTickets() const;

    void setExchangeTickets(int exchangeTickets);
};


#endif //LAYINGGRASS_PLAYER_H
