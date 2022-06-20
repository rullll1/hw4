//
// Created by rulll on 19/06/2022.
//

#ifndef HW4_GANG_H
#define HW4_GANG_H

#include <vector>
#include "Card.h"

class Gang: public Card {
public:
    Gang() = default;

    void addMonster(Card* monster);
    void applyEncounter(Player &player) override;
private:
    std::vector<Card*> gangCards;

};


#endif //HW4_GANG_H
