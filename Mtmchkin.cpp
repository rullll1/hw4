//
// Created by rulll on 09/06/2022.
//

#include "consts.h"
#include <iostream>
#include <fstream>
#include <string>
#include <map>
#include <functional>
#include <algorithm>

#include "Mtmchkin.h"

#include "Cards/Card.h"
#include "Cards/Barfight.h"
#include "Cards/BattleCard.h"
#include "Cards/Fairy.h"
#include "Cards/Pitfall.h"
#include "Cards/Treasure.h"
#include "Cards/Merchant.h"

#include "Cards/Dragon.h"
#include "Cards/Vampire.h"
#include "Cards/Goblin.h"
#include "Cards/Gang.h"

#include "Players/Fighter.h"
#include "Players/Wizard.h"
#include "Players/Rogue.h"


#include "utilities.h"
#include <limits>
#include "Exception.h"

bool validateName(std::string& name){
    bool contains_non_alpha
            = name.find_first_not_of("abcdefghijklmnopqrstuvwxyzQWERTYUIOPLKJHGFDSAZXCVBNM") != std::string::npos;
    return name.size() <= 15 && !contains_non_alpha;

}

bool isNumber(const std::string& s)
{
    std::string::const_iterator it = s.begin();
    while (it != s.end() && std::isdigit(*it)) ++it;
    return !s.empty() && it == s.end();
}

bool validateRole(std::string& role){

    for (size_t i=0; i < playerRoles.size(); i++){
        if (playerRoles[i] == role){
            return true;
        }
    }
    return false;
}


void Mtmchkin::populateDeck(const std::string& fileName){
    std::string line;
    std::ifstream myFile (fileName);
    int lineNumber = 1;
    int deckSize = 0;
    if (myFile.is_open()) {
        while (getline(myFile, line)) {
            if (line == GANG_BEGINING){
                addGang(myFile, &lineNumber, &deckSize);
            }
            else {
                this->addCard(line, lineNumber);
                lineNumber += 1;  // TODO: maybe move it to addCard ?
                deckSize += 1;  // TODO: maybe move it to addCard ?
            }
        }
        myFile.close();

    }
    else {
        throw DeckFileNotFound();
    }
    if (deckSize < 5){
        throw DeckFileInvalidSize();
    }


}

void Mtmchkin::setGameSize(){
    std::string gameSizeString;
    int gameSize = 0;
    bool valid = false;
    while (!valid){
        printEnterTeamSizeMessage();
        getline(cin, gameSizeString);
//        std::cin >> gameSizeString;
        if (isNumber(gameSizeString)){
            gameSize = std::stoi( gameSizeString);
        }
        if (std::cin.good() && gameSize >= 2 && gameSize <= 6){
            valid = true;
        }
        else {
            printInvalidTeamSize();
//            std::cin.clear();
//            std::cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');
        }
    }
    this->m_total_players = gameSize;
    this->m_currentPlayerCount = gameSize;

}

void parseInput(const std::string& input, std::string& name, std::string& role){
    int space = 0;
    for (std::string::size_type i = 0; i < input.size(); i++){
        if (input[i] == ' '){
            space = i;
            name = input.substr(0, space);
            role = input.substr(space + 1, input.size());
            break;
        }
    }



}

void Mtmchkin::populatePlayers(){
    std::cin.clear();
//    std::cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');
    for (int i=0; i < this->m_total_players; i++){
        printInsertPlayerMessage();
        // Type a number and press enter
        std::string name, role, input;
        std::getline(std::cin, input);
        parseInput(input, name, role);
        while (true){
            if (!validateName(name)){
                printInvalidName();
                std::getline(std::cin, input);
                parseInput(input, name, role);
            }
            else if (!validateRole(role)){
                printInvalidClass();
                std::getline(std::cin, input);
                parseInput(input, name, role);
            }
            else {
                break;
            }
        }
//        while (!validateName(name)){
//            printInvalidName();
//            std::getline(std::cin, input);
//            parseInput(input, name, role);
//        }
//        while (!validateRole(role)){
//            printInvalidClass();
//            std::getline(std::cin, input);
//            parseInput(input, name, role);
////            std::cin >> name >> role;
//        }

        Player* player;
        if (role == FIGHTER){
            player =  new Fighter(name);
        }
        else if (role == ROUGE){
            player = new Rouge(name);
        }
        else if (role == WIZARD){
            player = new Wizard(name);
        }
        this->m_playersQ.push(player);

    }
//    Player* p1 = new Rouge("RougeA");
//    Player* p2 = new Wizard("WizardA");
//    Player* p3 = new Wizard("WizardB");
//    Player* p4 = new Fighter("FigtherA");
//    Player* p5 = new Fighter("CopyCat");
//    Player* p6 = new Fighter("CopyCat");
//
//    this->m_playersQ.push(p1);
//    this->m_playersQ.push(p2);
//    this->m_playersQ.push(p3);
//    this->m_playersQ.push(p4);
//    this->m_playersQ.push(p5);
//    this->m_playersQ.push(p6);

}

Mtmchkin::Mtmchkin(const std::string fileName) {
    printStartGameMessage();
    this->m_cardMap[DRAGON] = new Dragon();
    this->m_cardMap[VAMPIRE] = new Vampire();
    this->m_cardMap[GOBLIN] = new Goblin();
    this->m_cardMap[FAIRY] = new Fairy();
    this->m_cardMap[BAR_FIGHT] = new Barfight();
    this->m_cardMap[TREASURE] = new Treasure();
    this->m_cardMap[PIT_FALL] = new Pitfall();
    this->m_cardMap[MERCHANT] = new Merchant();

//    this->m_cardMap.insert(std::make_pair(DRAGON, std::unique_ptr<Card>(new Dragon())));
//    this->m_cardMap.insert(std::make_pair(VAMPIRE, std::unique_ptr<Card>(new Vampire())));
//    this->m_cardMap.insert(std::make_pair(GOBLIN, std::unique_ptr<Card>(new Goblin())));
//    this->m_cardMap.insert(std::make_pair(FAIRY, std::unique_ptr<Card>(new Fairy())));
//    this->m_cardMap.insert(std::make_pair(BAR_FIGHT, std::unique_ptr<Card>(new Barfight())));
//    this->m_cardMap.insert(std::make_pair(TREASURE, std::unique_ptr<Card>(new Treasure())));
//    this->m_cardMap.insert(std::make_pair(PIT_FALL, std::unique_ptr<Card>(new Pitfall())));
//    this->m_cardMap.insert(std::make_pair(MERCHANT, std::unique_ptr<Card>(new Merchant())));




//    try{
//    }
//    catch(const DeckFileInvalidSize& e){
//        bool flag = true;
//        throw;
//    }

    try{
        populateDeck(fileName);
    }
    catch(const std::exception& e){
        deleteDeck();
        throw;
    }
    setGameSize();
    populatePlayers();
    this->m_rounds = 1;
}

int Mtmchkin::getNumberOfRounds() const {
    return this->m_rounds - 1;
}

void Mtmchkin::playCard(Player& player){
    Card* card = this->m_deck.front();
    this->m_deck.pop();

    card->applyEncounter(player);
    if (player.getLevel() == MAX_LEVEL){
        this->m_winners.push(&player);
    }
    else if (player.getHP() == 0){
        this->m_losers.push_back(&player);
    }
    player.setInGame();
    this->m_deck.push(card);
    if (player.isPlaying()){
        this->m_playersQ.push(&player);
    }
    else {
        this->m_currentPlayerCount -= 1;
    }
}

void Mtmchkin::playRound() {
    printRoundStartMessage(this->m_rounds);
    int nPlayersDuringRound = this->m_currentPlayerCount;
    for (int i=0; i < nPlayersDuringRound; i++){
        Player* player = this->m_playersQ.front();
        this->popPlayer();
        printTurnStartMessage(player->getName());
        this->playCard(*player);
//        this->m_playersQ.push(player);
    }
    this->incrementRounds();
    if (this->isGameOver()){
        printGameEndMessage();
    }

}

void Mtmchkin::validateCard(std::string& cardName, int lineNumber){
    if (!this->m_cardMap[cardName]){
        std::string error = "Deck File Error: File format error in line " + to_string(lineNumber);
        throw DeckFileFormatError(error);
    }
}

void Mtmchkin::addCard(std::string& cardName, int lineNumber) {
    validateCard(cardName, lineNumber);
    Card* card = this->m_cardMap[cardName];
//    std::cout << *card << std::endl;

    m_deck.push(card);
}

void Mtmchkin::addGang(std::ifstream& myFile, int* lineNumber, int* deckSize) {
    std::string cardName;
    Gang *gang = new Gang();
    *lineNumber += 1;
    while (getline(myFile, cardName) && cardName != GANG_END){
        validateCard(cardName, *lineNumber);
        Card* card = this->m_cardMap[cardName];
        gang->addMonster(card);
        *lineNumber += 1;
        *deckSize += 1;
    }
    this->m_deck.push(gang);

}

bool Mtmchkin::isGameOver() const {
    std::queue<Player*> playersQCopy = this->m_playersQ;
    for (size_t i=0; i < this->m_playersQ.size(); i++){
        Player* player = playersQCopy.front();

        if (player->isPlaying()){
            return false;
        }
        playersQCopy.pop();

    }
    return true;
}


void Mtmchkin::printLeaderBoard() const {  //TODO: CLEAN ASAP
    printLeaderBoardStartMessage();

//    Player* players[this->m_total_players];
    std::vector<Player*> players;
    std::vector<Player> playersPlaying;
    Player *p;
    for (int i=0; i < this->m_total_players; i ++){
        players.push_back(p);
    }

    int *level = new int[this->m_total_players];

    for (int i=0; i < this->m_total_players; i++){
        level[i] = 0;
    }

    std::queue<Player*> playersQCopy = this->m_playersQ;
//    std::queue<Player*> LosersQCopy = this->m_losers;
    std::queue<Player*> winnersQCopy = this->m_winners;


    for (int i=0; i < this->m_currentPlayerCount; i++){
        Player* player = playersQCopy.front();
        playersQCopy.pop();
        playersPlaying.push_back(*player);
//        playersPlaying[i] = *player;
        level[i] = player->getLevel();
    }
    int rank = 1;
    for (size_t i=0; i < this->m_winners.size() ; i++, rank++){
        Player* player = winnersQCopy.front();
        winnersQCopy.pop();
        printPlayerLeaderBoard(rank, *player);
    }

    for (int i=0; i < this->m_currentPlayerCount ; i++, rank++){
        printPlayerLeaderBoard(rank, playersPlaying[i]);
    }


//    for (size_t i=m_losers.size() - 1; i > -1 ; i--, rank++){
//        Player* player = m_losers[i];
////        LosersQCopy.pop();
//        printPlayerLeaderBoard(rank, *player);
//    }


    for (auto it = m_losers.rbegin(); it != m_losers.rend(); ++it, rank++)
    {
        printPlayerLeaderBoard(rank, **it);
    }

    delete[] level;

}

//template<class T>
void deletePlayersQ(std::queue<Player*>& objectQ){
    size_t size = objectQ.size();
    for (size_t i=0; i < size; i ++ ){
        Player* object = objectQ.front();
        objectQ.pop();
        delete object;
    }
}

void deleteLosers(std::vector<Player*>& vec){
    for (size_t i=0; i < vec.size(); i ++ ){
        Player* object = vec[i];
        delete object;
    }
}

void Mtmchkin::deleteDeck(){
    for (size_t i=0; i < N_CARD_TYPES; i ++ ){
        Card* card = this->m_cardMap[cardTypes[i]];
        delete card;
    }
}



void Mtmchkin::incrementRounds() {
    this->m_rounds += 1;
}


Mtmchkin::~Mtmchkin() {
    deletePlayersQ(this->m_playersQ);
    deleteLosers(this->m_losers);
    deletePlayersQ(this->m_winners);
    this->deleteDeck();
//    deletePlayersQ(this->m_deck);

}

