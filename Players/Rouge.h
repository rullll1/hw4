//
// Created by rulll on 09/06/2022.
//

#ifndef HW4_ROUGE_H
#define HW4_ROUGE_H
#include "Player.h"

class Rouge: public Player {
public:
    Rouge(const std::string& name);
    void addCoins(int coins) override;
};


#endif //HW4_ROUGE_H
