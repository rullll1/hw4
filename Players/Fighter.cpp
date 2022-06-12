//
// Created by rulll on 09/06/2022.
//

#include "Fighter.h"
#include "../consts.h"

int Fighter::getAttackStrength() {
    return 2 * this->m_force + this->m_level;
}

Fighter::Fighter(const std::string &name) : Player(name) {
    this->m_type = FIGHTER;
}
