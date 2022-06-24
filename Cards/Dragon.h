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
    Dragon();
    ~Dragon() = default;
    void printinfo() const override;
    void loseBattle(Player &player) override;
};


#endif //HW4_DRAGON_H
