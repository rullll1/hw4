//
// Created by rulll on 19/06/2022.
//

#include "Gang.h"
#include "BattleCard.h"
#include "../utilities.h"

void Gang::addMonster(BattleCard* monster) {
    this->gangCards.push_back(monster);
}

void Gang::applyEncounter(Player &player) {
    bool lost = false;
    for (BattleCard* monster: this->gangCards) {
        if (player.getAttackStrength() < monster->getAttackStrength() || lost){
            monster->loseBattle(player);
            lost = true;
        }
        else {
            player.addCoins(monster->getLoot());
        }
    }
    if (!lost){
        printWinBattle(player.getName(), "Gang");
        player.levelUp();
    }
}
