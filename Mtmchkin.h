#ifndef MTMCHKIN_H_
#define MTMCHKIN_H_

#include <string>
#include <queue>
#include <memory>
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
#include "Exception.h"

class Mtmchkin{

public:

    /*
    * C'tor of Mtmchkin class
    *
    * @param filename - a file which contains the cards of the deck.
    * @return
    *      A new instance of Mtmchkin.
    */
    Mtmchkin(const std::string fileName);


    Mtmchkin & operator=(const Mtmchkin&) = delete;

    ~Mtmchkin();




    /*
    * Play the next Round of the game - according to the instruction in the exercise document.
    *
    * @return
    *      void
    */
    void playRound();

    /*
    * Prints the leaderBoard of the game at a given stage of the game - according to the instruction in the exercise document.
    *
    * @return
    *      void
    */
    void printLeaderBoard() const;

    /*
    *  Checks if the game ended:
    *
    *  @return
    *          True if the game ended
    *          False otherwise
    */
    bool isGameOver() const;

    /*
    *  Returns the number of rounds played.
    *
    *  @return
    *          int - number of rounds played
    */
    int getNumberOfRounds() const;



//    std::queue<Player*> m_losers; // TODO: move to private
    std::queue<Player*> m_winners; // TODO: move to private



private:
    void addCard(std::string& cardName, int lineNumber);
    void addGang(ifstream& myFile, int *lineNumber, int *deckSize);


    void populateDeck(const std::string& fileName);
    void incrementRounds();
    void playCard(Player& player);
    void setGameSize();
    void populatePlayers();
    void deleteDeck();
    void validateCard(string &cardName, int lineNumber);


    void popPlayer(){  // TODO: delete later maybe
        this->m_playersQ.pop();
    }

    std::queue<Player*> m_playersQ;
    std::queue<Card*> m_deck;
    std::vector<Player*> m_losers;
//    std::map<std::string, std::unique_ptr<Card>> m_cardMap;
    std::map<std::string, Card*> m_cardMap;
    int m_currentPlayerCount;
    int m_total_players;
    int m_rounds = 0;


};



#endif /* MTMCHKIN_H_ */