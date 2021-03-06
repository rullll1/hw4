//
// Created by rulll on 11/06/2022.
//

#include <limits>
#include "Merchant.h"
#include "../utilities.h"


bool isStrNumber(const std::string& s)
{
    std::string::const_iterator it = s.begin();
    while (it != s.end() && std::isdigit(*it)) ++it;
    return !s.empty() && it == s.end();
}

void Merchant::applyEncounter(Player &player) {
    printMerchantInitialMessageForInteractiveEncounter(std::cout, player.getName(),
                                                       player.getCoins());

    int option = -1;
    std::string numberstring;
    bool valid = false;

    getline(cin, numberstring);
    while (!valid){
        if (isStrNumber(numberstring) &&
             (numberstring == to_string(NOT_BUYING) || numberstring == to_string(HP_OPTION) ||
            numberstring == to_string(BOOST_OPTION))){
                option = std::stoi( numberstring);
                valid = true;
            }


        else {
            printInvalidInput();
//            std::cin.clear();
//            std::cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');
//            printMerchantInitialMessageForInteractiveEncounter(std::cout, player.getName(),
//                                                               player.getCoins());
            getline(cin, numberstring);

        }
    }
    int price = 0;

    switch (option) {
        case HP_OPTION:
            price = HP_POTION_PRICE;
            player.buyHPPotion(&price);
            break;
        case BOOST_OPTION:
            price = BOOST_POTION_PRICE;
            player.buyBoostPotion(&price);
            break;
    }

    printMerchantSummary(std::cout, player.getName(), option, price);
}