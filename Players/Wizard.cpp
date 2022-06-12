//
// Created by rulll on 09/06/2022.
//

#include <iostream>
#include "Wizard.h"
#include "../consts.h"

void Wizard::heal(int hp) {
    hp = std::max(0, hp) * 2;
    this->m_HP = std::min(this->m_HP + hp, this->m_maxHP);
}

Wizard::Wizard(const std::string &name) : Player(name) {
    this->m_type = WIZARD;
}
