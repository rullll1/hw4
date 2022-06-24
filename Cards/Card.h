//
// Created by Daniel_Meents on 07/04/2022.
//
#ifndef EX2_Card_H
#define EX2_Card_H

#include <string>
#include "../Players/Player.h"
#include "../consts.h"

struct CardStats{
    int force;  // The force of the monster
    int loot; // The profit you get when winning a battle or when getting a "Treasure" card
    int hpLossOnDefeat; // The amount of hp you lose when losing the battle

    int cost; // The cost of a "Buff/Heal" card
    int heal; // The amount of HP you get when buying a "HEAL" card
    int buff; // The amount of force you get when buying a "BUFF" card


    /*
     *C'tor of CardStats:
     *
     * @param force - The force of the card (monster).
     * @param hpLoss - HP loss when losing the battle.
     * @param cost - The cost of the card when is type is "Buff" or "Heal".
     * @param heal - The amount of HP is given when buying a "Heal" card.
     * @param buff - The amount of force is given when buying a "Buff" card.
     * @param loot - The profit from winning a battle or when getting a "Treasure" card.
     * @return
     *      New instance of CardStats.
    */
    explicit CardStats(int force = 0, int hpLoss = 0, int cost = 0, int heal = 0, int buff = 0, int loot = 0) {
        this->force = force;
        this->hpLossOnDefeat = hpLoss;
        this->cost = cost;
        this->heal = heal;
        this->buff = buff;
        this->loot = loot;
    }
};




/*
 *  CardType:
 *  Each card has an type:
 *  BATTLE - Battle against a monster.
 *  BUFF - Increase your player's force by 'm_force' points of CardStats.
 *  HEAL - Increase your player's HP by 'm_heal' points  of CardStats (no more than maxHP points).
 *  TREASURE - Get 'm_profit' coins of CardStats.
*/
enum class CardType {Battle, Buff, Heal, Treasure}; // The type of the Card

class Card {
public:
    /*
     * C'tor of Card class
     *
     * @param type - The type of the card.
     * @param stats - The numeral stats of the card.
     * @return
     *      A new instance of Card.
    */
    Card() = default;

    /*
     * Handling the player's applyEncounter with the card:
     *
     * @param player - The player.
     * @return
     *      void
    */
    virtual void applyEncounter(Player& player);



    virtual void printinfo() const;

    const std::string& getName() const;



    /*
     * C'tor to the "default card" - Treasure card that gives 0 coins
    */

    /*
     * Here we are explicitly telling the compiler to use the default methods
    */
    Card(const Card&) = default;
    virtual ~Card() = default;
    Card& operator=(const Card& other) = default;


    friend std::ostream& operator<<(std::ostream& os, const Card& card);



private:

protected:
    std::string m_name = "Card";
};



#endif //EX2_Card_H