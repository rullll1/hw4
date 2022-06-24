//
// Created by rulll on 19/06/2022.
//

#ifndef HW4_GANG_H
#define HW4_GANG_H

#include <vector>
#include "Card.h"
#include "BattleCard.h"

class Gang: public Card {
public:
    Gang(){this->m_name = GANG_BEGINING;}
    ~Gang() = default;
    void addMonster(BattleCard* monster);
    void applyEncounter(Player &player) override;

private:
    std::vector<BattleCard*> gangCards;

};


#endif //HW4_GANG_H
