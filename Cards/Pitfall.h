//
// Created by rulll on 09/06/2022.
//

#ifndef HW4_PITFALL_H
#define HW4_PITFALL_H

#include "Card.h"

class Pitfall: public Card {
public:
    Pitfall(){this->m_name = PIT_FALL;}
    void applyEncounter(Player &player) override;
};


#endif //HW4_PITFALL_H
