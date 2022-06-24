//
// Created by Daniel_Meents on 07/04/2022.
//
#ifndef EX2_Card_H
#define EX2_Card_H

#include <string>
#include "../Players/Player.h"
#include "../consts.h"

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


    /*
     * Prints card stats
     */
    virtual void printinfo() const;

    /*
     * returns card name
     */
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