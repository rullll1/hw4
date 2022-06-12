//
// Created by rulll on 11/06/2022.
//

#ifndef HW4_MERCHANT_H
#define HW4_MERCHANT_H

#include "Card.h"


class Merchant: public Card {
public:
    Merchant(){this->m_name = MERCHANT;}
    void applyEncounter(Player &player) override;
};


#endif //HW4_MERCHANT_H
