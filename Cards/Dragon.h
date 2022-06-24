//
// Created by rulll on 09/06/2022.
//

#ifndef HW4_DRAGON_H
#define HW4_DRAGON_H

#include "Card.h"
#include "BattleCard.h"
#include "../consts.h"

class Dragon: public BattleCard {
public:
//    Dragon(){
//        this->m_name = DRAGON;
//        this->m_force = 25;
//    }
    Dragon();
    ~Dragon() = default;
    void printinfo() const override;
    void loseBattle(Player &player) override;

private:
    CardType m_type;
//    int m_force = 25;  // The force of the monster
//    int m_loot = 1000; // The profit you get when winning a battle or when getting a "Treasure" card
//    int m_hpLossOnDefeat = MAX_HP; // The amount of hp you lose when losing the battle
};


#endif //HW4_DRAGON_H
