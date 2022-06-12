//
// Created by rulll on 09/06/2022.
//

#include "Dragon.h"
#include "../utilities.h"

void Dragon::printinfo() const {
    printMonsterDetails(std::cout, this->m_force, this->m_hpLossOnDefeat, this->m_loot, true);
    printEndOfCardDetails(std::cout);

}

Dragon::Dragon() {
    this->m_name = DRAGON;
    this->m_force = 25;
    this->m_loot = 1000; // The profit you get when winning a battle or when getting a "Treasure" card
    this->m_hpLossOnDefeat = MAX_HP; // The amount of hp you lose when losing the battle

}
