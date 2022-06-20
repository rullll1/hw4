//
// Created by rulll on 09/06/2022.
//

#include "consts.h"
#include <iostream>
#include <fstream>
#include <string>
#include <map>
#include <functional>

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
    return name.size() <= 15;
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
    int gameSize;
    bool valid = false;
    while (!valid){
        printEnterTeamSizeMessage();
        std::cin >> gameSize;
        if (std::cin.good() && gameSize >= 2 && gameSize <= 6){
            valid = true;
        }
        else {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');
        }
    }
    this->m_total_players = gameSize;
    this->m_currentPlayerCount = gameSize;

}

void Mtmchkin::populatePlayers(){

    for (int i=0; i < this->m_total_players; i++){
        printInsertPlayerMessage();
        // Type a number and press enter
        std::string name, role;

        std::cin >> name >> role;
        while (!validateName(name)){
            printInvalidName();
            std::cin >> name >> role;
        }
        while (!validateRole(role)){
            printInvalidClass();
            std::cin >> name >> role;
        }

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
        this->m_losers.push(&player);
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

    Player *p;
    for (int i=0; i < this->m_total_players; i ++){
        players.push_back(p);
    }

    int *level = new int[this->m_total_players];

    for (int i=0; i < this->m_total_players; i++){
        level[i] = 0;
    }

    int bottomIndex = 0;
    int upperIndex = this->m_total_players - 1;
    std::queue<Player*> playersQCopy = this->m_playersQ;
    std::queue<Player*> LosersQCopy = this->m_losers;
    std::queue<Player*> winnersQCopy = this->m_winners;



    size_t index = 0;

    for (; index < this->m_losers.size(); bottomIndex++, index++){
        Player* player = LosersQCopy.front();
        LosersQCopy.pop();
        players[bottomIndex] = player;
        level[bottomIndex] = player->getLevel();
    }

    for (; !winnersQCopy.empty(); upperIndex--){
        Player* player = winnersQCopy.front();
        winnersQCopy.pop();
        players[upperIndex] = player;
        level[upperIndex] = player->getLevel();
    }


    for (; bottomIndex < upperIndex + 1; bottomIndex++){
        Player* player = playersQCopy.front();
        playersQCopy.pop();
        players[bottomIndex] = player;
        level[bottomIndex] = player->getLevel();
    }

    for (int i=0; i<this->m_total_players; i++){
        Player* player = players[i];
        if (player->isPlaying()){
            for (int j=i + 1; j<this->m_total_players; j++){
                if (player->getLevel() >= players[j]->getLevel()){
                    Player* tempPlayer = player;
                    int tempLevel = level[i];
                    players[i] = players[j];
                    players[j] = tempPlayer;
                    level[i] = level[j];
                    level[j] = tempLevel;
                }
            }
        }

    }


    for (int i=this->m_total_players - 1; i >= 0 ; i--){
        printPlayerLeaderBoard(this->m_total_players - i, *players[i]);
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
    deletePlayersQ(this->m_losers);
    deletePlayersQ(this->m_winners);
    this->deleteDeck();
//    deletePlayersQ(this->m_deck);

}

