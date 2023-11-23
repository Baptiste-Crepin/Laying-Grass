//
// Created by Baptiste Crepin on 17/11/2023.
//

#include "Player.h"
#include <iostream>
#include <string>

#define RESET   "\033[0m"
#define RED     "\033[31m"
#define GREEN   "\033[32m"
#define YELLOW  "\033[33m"
#define BLUE    "\033[34m"
#define MAGENTA "\033[35m"
#define CYAN    "\033[36m"

Player::Player(int id, std::string name, std::string color) : id(id), name(name), color(color) {}

Player::Player() {}

Player::~Player() {
//    std::cout << "deleted" << std::endl;
}

int Player::getId() const { return id; }

std::string Player::getColor() const { return color; }

std::string Player::getName() const { return name; }

int Player::getExchangeTickets() const { return exchangeTickets; }

void Player::setExchangeTickets(int exchangeTickets) { Player::exchangeTickets = exchangeTickets; }
