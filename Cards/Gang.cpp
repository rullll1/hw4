//
// Created by rulll on 19/06/2022.
//

#include "Gang.h"

void Gang::addMonster(Card* monster) {
    this->gangCards.push_back(monster);
}

void Gang::applyEncounter(Player &player) {
    for(Card* value: this->gangCards) {
        std::cout << *value << "\n";
    }
}
