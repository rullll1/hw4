//
// Created by rulll on 09/06/2022.
//

#include "Barfight.h"
#include "../utilities.h"
#include "../consts.h"



const int BAR_FIGHT_DAMAGE = 10;

void Barfight::applyEncounter(Player &player) {
    if (player.m_type != FIGHTER){
        player.damage(BAR_FIGHT_DAMAGE);
    }
    printBarfightMessage(player.m_type == FIGHTER);
}

