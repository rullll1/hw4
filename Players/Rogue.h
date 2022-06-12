//
// Created by rulll on 09/06/2022.
//

#ifndef HW4_ROGUE_H
#define HW4_ROGUE_H
#include "Player.h"

class Rouge: public Player {
public:
    Rouge(const std::string& name);
    void addCoins(int coins) override;
};


#endif //HW4_ROGUE_H
