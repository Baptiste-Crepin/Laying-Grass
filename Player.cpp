//
// Created by Baptiste Crepin on 17/11/2023.
//

#include "Player.h"

Player::Player(int id, std::string name) : id(id), name(name) {}
Player::Player() {}
Player::~Player() {}

int Player::getId() const {return id;}
const std::string &Player::getName() const {return name;}
