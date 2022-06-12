//
// Created by rulll on 09/06/2022.
//
#include "Rogue.h"
#include "../consts.h"
#include <iostream>

void Rouge::addCoins(int coins) {
    coins = std::max(0, coins);
    this->m_money += 2 * coins;
}

Rouge::Rouge(const std::string &name) : Player(name) {
    this->m_type = ROUGE;
}
