//
// Created by rulll on 09/06/2022.
//

#ifndef HW4_CONSTS_H
#define HW4_CONSTS_H

#include <string>
#include <functional>
#include <map>
#include <vector>

const int MAX_LEVEL = 10;
const int MAX_HP = -999;
const std::string GOBLIN =  "Goblin";
const std::string DRAGON =  "Dragon";
const std::string VAMPIRE =  "Vampire";
const std::string FAIRY =  "Fairy";
const std::string BAR_FIGHT =  "Barfight";
const std::string TREASURE =  "Treasure";
const std::string MERCHANT =  "Merchant";
const std::string PIT_FALL =  "Pitfall";




const std::vector<std::string> cardTypes = {GOBLIN, DRAGON, VAMPIRE, FAIRY, BAR_FIGHT, TREASURE, MERCHANT, PIT_FALL};


const std::string FIGHTER =  "Fighter";
const std::string ROUGE =  "Rogue";
const std::string WIZARD =  "Wizard";

const std::vector<std::string> playerRoles = {FIGHTER, ROUGE, WIZARD};


const int HP_POTION_PRICE = 5;
const int BOOST_POTION_PRICE = 10;
const int NOT_BUYING = 0;
const int HP_OPTION = 1;
const int BOOST_OPTION = 2;
const int POTION_HEAL = 1;
const int BOOST_BUFF = 1;

//int tester(){
//    printf("lets go");
//    return 5;
//}

//std::map<std::string, std::function<void()>> functionCallMap;
//std::map<std::string, int> functionCallMap1;
//
////const std::map<std::string, std::function<void()>> my_map = {
////        { "Cat", tester },
////        { "Dog", tester },
////        { "Fish", tester }
////};
//void functionCallMap["test"] =  tester;







#endif //HW4_CONSTS_H
