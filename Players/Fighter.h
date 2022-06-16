//
// Created by rulll on 09/06/2022.
//

#ifndef HW4_FIGHTER_H
#define HW4_FIGHTER_H
#include "Player.h"

class Fighter final : public Player{
public:
    Fighter(const std::string& name);
    int getAttackStrength() override;
};


#endif //HW4_FIGHTER_H
