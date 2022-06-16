//
// Created by rulll on 09/06/2022.
//

#include "Mtmchkin.h"
#include "consts.h"
#include <iostream>
#include <fstream>
#include <string>
#include <map>
#include <functional>
#include "Cards/Card.h"
#include "Cards/Barfight.h"
#include "Cards/BattleCard.h"
#include "Cards/Dragon.h"
#include "Cards/Fairy.h"
#include "Cards/Goblin.h"
#include "Cards/Pitfall.h"
#include "Cards/Treasure.h"
#include "Cards/Vampire.h"
#include "Cards/Merchant.h"

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
    if (myFile.is_open()) {
        while (getline(myFile, line)) {
            this->addCard(line, lineNumber);
            lineNumber += 1;
        }
        myFile.close();

    }
    else {
        throw DeckFileNotFound();
    }
    if (lineNumber < 5){
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

    this->m_cardMap[DRAGON] = new Dragon();
    this->m_cardMap[VAMPIRE] = new Vampire();
    this->m_cardMap[GOBLIN] = new Goblin();
    this->m_cardMap[FAIRY] = new Fairy();
    this->m_cardMap[BAR_FIGHT] = new Barfight();
    this->m_cardMap[TREASURE] = new Treasure();
    this->m_cardMap[PIT_FALL] = new Pitfall();
    this->m_cardMap[MERCHANT] = new Merchant();
    printStartGameMessage();
    populateDeck(fileName);
    setGameSize();
    populatePlayers();
    this->m_rounds = 1;
}

int Mtmchkin::getNumberOfRounds() const {
    return this->m_rounds;
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

void Mtmchkin::addCard(std::string& cardName, int lineNumber) {
    if (!this->m_cardMap[cardName]){
        throw DeckFileFormatError("Deck File Error: File format error in line " + to_string(lineNumber));
    }
    Card* card = this->m_cardMap[cardName];
//    std::cout << *card << std::endl;

    m_deck.push(card);
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

    Player* players[this->m_total_players];
    int level[this->m_total_players];

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

}

void Mtmchkin::incrementRounds() {
    this->m_rounds += 1;
}
