//
// Created by rulll on 09/06/2022.
//

#include "Vampire.h"
#include "../consts.h"
#include "../utilities.h"



void Vampire::handleBattleCard(Player &player, int force, int loot, int damageTaken) {
    if (player.getAttackStrength() >= force){
        player.levelUp();
        player.addCoins(loot);
        printWinBattle(player.getName(), this->getName());
//        printBattleResult(true);
    }
    else {
        if (damageTaken == MAX_HP){
            damageTaken = player.getHP();
        }
        player.debuff(1);
        player.damage(damageTaken);
        printLossBattle(player.getName(), this->getName());
//        printBattleResult(false);
    }
}

void Vampire::printinfo() const {
    printCardDetails(std::cout, this->getName());
    printMonsterDetails(std::cout, this->m_force, this->m_hpLossOnDefeat, this->m_loot);
    printEndOfCardDetails(std::cout);
}

Vampire::Vampire() {

    this->m_name = VAMPIRE;
    this->m_force = 10;  // The force of the monster
    this->m_loot = 2; // The profit you get when winning a battle or when getting a "Treasure" card
    this->m_hpLossOnDefeat = 10; // The amount of hp you lose when losing the battle

}
