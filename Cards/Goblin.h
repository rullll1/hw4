//
// Created by rulll on 09/06/2022.
//

#ifndef HW4_GOBLIN_H
#define HW4_GOBLIN_H

#include "BattleCard.h"

class Goblin: public BattleCard {
public:
//    void applyEncounter(Player &player) override;
    Goblin();
    void printinfo() const override;

private:
    CardType m_type;
//    int m_force = 6;  // The force of the monster
//    int m_loot = 2; // The profit you get when winning a battle or when getting a "Treasure" card
//    int m_hpLossOnDefeat = 10; // The amount of hp you lose when losing the battle
};


#endif //HW4_GOBLIN_H
