//
// Created by rulll on 09/06/2022.
//

#include "Treasure.h"
#include "../utilities.h"

const int TREASURE_COINS = 10;

void Treasure::applyEncounter(Player &player) {
    player.addCoins(TREASURE_COINS);
    printTreasureMessage();
}
