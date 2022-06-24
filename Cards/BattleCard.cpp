//
// Created by rulll on 09/06/2022.
//

#include "BattleCard.h"
#include "../utilities.h"

void BattleCard::applyEncounter(Player &player) {
    handleBattleCard(player);
}

int BattleCard::getAttackStrength() {
    return this->m_force;
}

int BattleCard::getHpLossOnDefeat() {
    return this->m_hpLossOnDefeat;
}

void BattleCard::loseBattle(Player &player) {
    int damageTaken = this->getHpLossOnDefeat();
    player.damage(damageTaken);
    printLossBattle(player.getName(), this->getName());
}

void BattleCard::winBattle(Player& player){
    player.levelUp();
    player.addCoins(this->getLoot());
    printWinBattle(player.getName(), this->getName());
}

void BattleCard::handleBattleCard(Player& player)
{
    if (player.getAttackStrength() >= this->getAttackStrength()){
        winBattle(player);
    }
    else {
        loseBattle(player);
    }
}


int BattleCard::getLoot() {
    return this->m_loot;
}
