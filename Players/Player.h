//
// Created by rulll on 02/05/2022.
//

#ifndef HW2_PLAYER_H
#define HW2_PLAYER_H

#include <string>
#include <iostream>

enum class PlayerType {Fighter, Rouge, Wizard, Player};


class Player {
    std::string m_name;
protected:
    bool inGame = true;
    int m_HP;
    int m_maxHP;
    int m_money;
    int m_force;
    int m_level;
public:
    std::string m_type;
    /*
     * C'tor for Player
     */
    Player(const std::string& name);

    Player(const Player&) = default;
    ~Player() = default;
    /*
     * prints Player info per exercise document
     */
    virtual void printInfo() const;

    /*
     * increments level attribute by 1
     */
    void levelUp();
    /*
     * getter for level attribute
     */
    int getLevel() const;
    /*
     * increases force attribute
     */
    void buff(int bonus);
    /*
    * increases hp attribute
    */

    void debuff(int bonus);
    /*
    * increases hp attribute
    */

    virtual void heal(int hp);
    /*
    * decreases hp attribute
    */
    void damage(int hp);
    /*
     * returns true if hp attr is 0
     */
    bool isKnockedOut();
    /*
     * increases money attr
     */
    virtual void addCoins(int coins);
    /*
    * decreases money attr
    */
    bool pay(int coins);
    /*
     * getter for level + force attr
     */
    virtual int getAttackStrength();

    /*
    * getter for current hp of the player
    */
    int getHP() const;

    const std::string& getName() const;

    bool isPlaying() const;

    int getCoins() const;

    const std::string& getType() const;

    int calculateScore() const;

    void buyHPPotion();

    void buyBoostPotion();

    void setInGame();

    friend std::ostream& operator<<(std::ostream& os, const Player& player);
};



#endif //HW2_PLAYER_H