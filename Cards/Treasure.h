//
// Created by rulll on 09/06/2022.
//

#ifndef HW4_TREASURE_H
#define HW4_TREASURE_H

#include "Card.h"

class Treasure: public Card{
public:
    Treasure(){this->m_name = TREASURE;}
    void applyEncounter(Player &player) override;
};


#endif //HW4_TREASURE_H
