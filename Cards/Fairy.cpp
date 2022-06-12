//
// Created by rulll on 09/06/2022.
//

#include "Fairy.h"
#include "../utilities.h"
#include "../consts.h"

const int HP_BONUS = 10;

void Fairy::applyEncounter(Player &player) {
    if (player.m_type == WIZARD){
        player.heal(HP_BONUS);
    }
    printFairyMessage(player.m_type == WIZARD);
}