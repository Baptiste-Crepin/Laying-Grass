//
// Created by Baptiste Crepin on 17/11/2023.
//

#include "Player.h"

//Player::Player(int id, std::string name) : id(id), name(name) {}
int startingTickets = 1;

Player::Player(int id) : id(id) {}

Player::Player() {}

Player::~Player() {}

int Player::getId() const { return id; }

int Player::getExchangeTickets() const { return exchangeTickets; }
//const std::string &Player::getName() const {return name;}
