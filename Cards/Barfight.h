//
// Created by rulll on 09/06/2022.
//

#ifndef HW4_BARFIGHT_H
#define HW4_BARFIGHT_H

#include "Card.h"

class Barfight: public Card {
public:
    Barfight(){this->m_name = BAR_FIGHT;}

    void applyEncounter(Player &player) override;
};

#endif //HW4_BARFIGHT_H
