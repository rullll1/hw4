//
// Created by Owner on 13/06/2022.
//

#include "../Mtmchkin.h"


int main() {
    const std::string FILE_NAME = "deck.txt";
    try {
        Mtmchkin game = Mtmchkin(FILE_NAME);
        while (!game.isGameOver()){
            game.playRound();
        }
    }
    catch (DeckFileNotFound& e){
        return EXIT_SUCCESS;
    }
    catch (DeckFileInvalidSize& e){
        return EXIT_SUCCESS;
    }
    catch (DeckFileFormatError& e){
        return EXIT_SUCCESS;
    }
}