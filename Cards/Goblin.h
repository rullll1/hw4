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
};


#endif //HW4_GOBLIN_H
