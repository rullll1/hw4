#include <string>
#include <iostream>
#include <vector>
#include "../Mtmchkin.h"
#include <algorithm>

using std::cout;
using std::cerr;
using std::string;
using std::endl;

int main()
{
    const int MAX_NUMBER_OF_ROUNDS = 100;
    std::string FILE_NAME = "deck.txt";
    try
    {
        Mtmchkin game(FILE_NAME);
        while(!game.isGameOver() && game.getNumberOfRounds() < MAX_NUMBER_OF_ROUNDS){
            game.playRound();
            game.printLeaderBoard();
        }
    }
    catch (std::exception &e)
    {
        std::cout << e.what();
    }
}

