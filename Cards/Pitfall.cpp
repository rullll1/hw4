//
// Created by rulll on 09/06/2022.
//

#include "Pitfall.h"
#include "../utilities.h"
#include "../consts.h"


const int PIT_FALL_DAMAGE = 10;

void Pitfall::applyEncounter(Player &player) {
    if (player.m_type != ROUGE){
        player.damage(PIT_FALL_DAMAGE);
    }
    printPitfallMessage(player.m_type == ROUGE);

}