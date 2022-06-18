//
// Created by stava on 6/15/2022.
//


#include <string>
#include <iostream>
#include <vector>
#include <memory>
#include "Mtmchkin.h"
#include <algorithm>

using std::unique_ptr;
using std::cout;
using std::cerr;
using std::string;
using std::endl;

int main()
{
    const int MAX_NUMBER_OF_ROUNDS = 100;
    try {
        Mtmchkin game("deck.txt");
        while (!game.isGameOver() && game.getNumberOfRounds() < MAX_NUMBER_OF_ROUNDS) {
            game.playRound();
        }
        game.printLeaderBoard();
    } catch(const std::exception &e){
        cerr << e.what() << endl;
    }
}
