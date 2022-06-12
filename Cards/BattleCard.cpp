//
// Created by rulll on 09/06/2022.
//

#include "BattleCard.h"

void BattleCard::applyEncounter(Player &player) {
    handleBattleCard(player, this->m_force, this->m_loot, this->m_hpLossOnDefeat);
}