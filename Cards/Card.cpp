//
// Created by rulll on 03/05/2022.
//
#include "Card.h"
#include "../consts.h"
#include "../utilities.h"


Card::Card(CardType type, const CardStats& stats) {
        this->m_effect = type;
        this->m_name = "Card";
    }




//void Card::printInfo() const {
//    switch (this->m_effect) {
//        case CardType::Battle:
//            printBattleCardInfo(this->m_stats);
//            break;
//        case CardType::Buff:
//            printBuffCardInfo(this->m_stats);
//            break;
//        case CardType::Heal:
//            printHealCardInfo(this->m_stats);
//            break;
//        case CardType::Treasure:
//            printTreasureCardInfo(this->m_stats);
//            break;
//    }
//}

//void Card::handleBattleCard(Player& player, int force, int loot, int damageTaken)
//    {
//        if (player.getAttackStrength() >= force){
//            player.levelUp();
//            player.addCoins(loot);
//            printWinBattle(player.getName(), this->getName());
//
//
////        printBattleResult(true);
//        }
//        else {
//            if (damageTaken == MAX_HP){
//                damageTaken = player.getHP();
//            }
//            player.damage(damageTaken);
//            printLossBattle(player.getName(), this->getName());
////        printBattleResult(false);
//        }
//    }

void handleHealCard(Player& player, int cost, int hp){
    if (player.pay(cost)){
        player.heal(hp);
    }
}

void handleBuffCard(Player& player, int cost, int force){
    if (player.pay(cost)){
        player.buff(force);
    }
}

void handleTreasureCard(Player& player, int coins){
    player.addCoins(coins);
}

void Card::applyEncounter(Player &player) {
}

 const std::string& Card::getName() const{
    return this->m_name;
}


void Card::printinfo() const {
    printCardDetails(std::cout, this->getName());
    printEndOfCardDetails(std::cout);
}



std::ostream& operator<<(std::ostream& os, const Card& card)
{
    card.printinfo();
    return os;
}

