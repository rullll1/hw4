//
// Created by rulll on 09/06/2022.
//

#ifndef HW4_BATTLECARD_H
#define HW4_BATTLECARD_H

#include "Card.h"

class BattleCard: public Card {
public:
    void applyEncounter(Player &player) override;
// The amount of hp you lose when losing the battle
protected:
    int m_force;
// The force of the monster
int m_loot;
// The profit you get when winning a battle or when getting a "Treasure" card
int m_hpLossOnDefeat;
};


#endif //HW4_BATTLECARD_H
