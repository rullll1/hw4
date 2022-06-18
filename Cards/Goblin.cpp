//
// Created by rulll on 09/06/2022.
//

#include "Goblin.h"
#include "../Players/Player.h"
#include "../consts.h"
#include "../utilities.h"

Goblin::Goblin() {
    this->m_name = GOBLIN;
    this->m_force = 6;  // The force of the monster
    this->m_loot = 2; // The profit you get when winning a battle or when getting a "Treasure" card
    this->m_hpLossOnDefeat = 10; // The amount of hp you lose when losing the battle
}

void Goblin::printinfo() const {
    printCardDetails(std::cout, this->getName());
    printMonsterDetails(std::cout, this->m_force, this->m_hpLossOnDefeat, this->m_loot);
    printEndOfCardDetails(std::cout);

}

