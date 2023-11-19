//
// Created by Baptiste Crepin on 17/11/2023.
//

#ifndef LAYINGGRASS_PLAYER_H
#define LAYINGGRASS_PLAYER_H

//#include <string>

class Player {
private:
    int id;
    //std::string name;
    int exchangeTickets = 1;

public:
    Player(int id);//, std::string name); //Todo: add names back
    Player();

    ~Player();

    int getId() const;

    int getExchangeTickets() const;

    // const std::string &getName() const;
};


#endif //LAYINGGRASS_PLAYER_H
