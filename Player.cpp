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
int startingTickets = 1;

//Player::Player(int id) : id(id) {}
//Player::Player(int id) : id(id) {}

Player::Player() {}

Player::~Player() {
    std::cout << "deleted" << std::endl;
}

void Player::displayPlayerInfo() const {         //TODO: Couleur fonctionne dans le main mais pas ici ??
    switch (color[0]) {
        case 'r':
            std::cout << RED << "Player " << RESET << std::endl;
            break;
        case 'g':
            std::cout << GREEN << "Player " << std::endl;
            break;
        case 'y':
            std::cout << YELLOW << "Player " << std::endl;
            break;
        case 'b':
            std::cout << BLUE << "Player " << std::endl;
            break;
        case 'm':
            std::cout << MAGENTA << "Player " << id << " | " << name << " | " << color << " | " << exchangeTickets << " exchange tickets" << RESET << std::endl;
            break;
        case 'c':
            std::cout << CYAN << "Player " << id << " | " << name << " | " << color << " | " << exchangeTickets << " exchange tickets" << RESET << std::endl;
            break;
        default:
            std::cout << "FFFF" << std::endl;
            break;

    }
    std::cout << "Player " << id << " | " << name << " | " << color << " | " << exchangeTickets << " exchange tickets" << std::endl;
}

int Player::getId() const { return id; }

void Player::setName(std::string name) { Player::name = name; }

void Player::setColor(std::string color) { Player::color = color; }

std::string Player::getColor() const { return color; }

std::string Player::getName() const { return name; }

int Player::getExchangeTickets() const { return exchangeTickets; }

void Player::setExchangeTickets(int exchangeTickets) { Player::exchangeTickets = exchangeTickets; }
//const std::string &Player::getName() const {return name;}
