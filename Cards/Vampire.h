//
// Created by rulll on 09/06/2022.
//

#ifndef HW4_VAMPIRE_H
#define HW4_VAMPIRE_H

#include "Card.h"
#include "BattleCard.h"

class Vampire: public BattleCard {
public:
    Vampire();
    void printinfo() const override;
    void handleBattleCard(Player &player, int force, int loot, int damageTaken) override;
private:
    CardType m_type;
};



#endif //HW4_VAMPIRE_H
