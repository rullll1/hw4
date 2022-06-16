//
// Created by rulll on 09/06/2022.
//

#ifndef HW4_WIZARD_H
#define HW4_WIZARD_H
#include "Player.h"
#include <string>

class Wizard final : public Player{
public:
    Wizard(const std::string& name);
    ~Wizard() override = default;

//    using Player::Player;
    void heal(int hp) override;
};


#endif //HW4_WIZARD_H
