//
// Created by rulll on 09/06/2022.
//

#ifndef HW4_FAIRY_H
#define HW4_FAIRY_H

#include "Card.h"

class Fairy: public Card {
public:
    Fairy(){this->m_name = FAIRY;}
    void applyEncounter(Player &player) override;
};



#endif //HW4_FAIRY_H
