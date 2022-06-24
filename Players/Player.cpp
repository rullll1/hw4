//
// Created by rulll on 02/05/2022.
//
#include <iostream>
#include "Player.h"
#include "../consts.h"
#include "../utilities.h"

int max(int a, int b){
    if (a > b){
        return a;
    }
    return b;
}

int min(int a, int b){
    if (a > b){
        return b;
    }
    return a;
}


int handleNegativeValue(int value, int defaultValue){
    if (value <= 0 ){
        return defaultValue;
    }
    return value;
}


Player::Player(const std::string& name) {
    this->m_name = name;
    this->m_HP = this->m_maxHP;
    this->m_money = 10;
    this->m_level = 1;
    this->m_maxHP = 100;
    this->m_HP = this->m_maxHP;
    this->m_force = 5;

}

void Player::printInfo() const {
    printPlayerDetails(std::cout, this->getName(), this->getType(), this->getLevel(), this->m_force,
                       this->getHP(), this->getCoins());
}

void Player::levelUp(){
    this->m_level += 1;
    if (this->m_level > 10){
        this->m_level = 10;
    }
}

const std::string& Player::getName() const {
    return this->m_name;
}

int Player::getLevel() const {
    return this->m_level;
}

void Player::buff(int bonus) {

    this->m_force += max(bonus, 0);
}

void Player::debuff(int bonus) {

    this->m_force -= bonus;
    this->m_force = max(this->m_force, 0);
}

void Player::heal(int hp) {
    hp = max(0, hp);
    this->m_HP = min(this->m_HP + hp, this->m_maxHP);
}

void Player::damage(int hp) {
    if (hp == MAX_HP){
        this->m_HP = 0;
        return;
    }
    hp = max(0, hp);
    this->m_HP = max(this->m_HP - hp, 0);
}

bool Player::isKnockedOut() {
    if (this->m_HP == 0){
        return true;
    }
    return false;
}

void Player::addCoins(int coins) {
    coins = max(0, coins);
    this->m_money += max(coins, 0);
}

bool Player::pay(int coins) {
    coins = max(0, coins);
    if (this->m_money >= coins){
        this->m_money -= coins;
        return true;
    }
    return false;
}

int Player::getAttackStrength() {
    return this->m_force + this->m_level;
}

int Player::getHP() const {
    return this->m_HP;
}

bool Player::isPlaying() const {
    if (this->m_HP <= 0 || this->getLevel() == MAX_LEVEL){
        return false;
    }
    return true;
}

int Player::calculateScore() const {
    if (this->m_HP == 0){
        return 0;
    }
    return this->getLevel();
}


int Player::getCoins() const {
    return this->m_money;
}


const std::string &Player::getType() const {
    return this->m_type;
}


std::ostream& operator<<(std::ostream& os, const Player& player)
{
    player.printInfo();
    return os;
}

void Player::setInGame() {
    this->inGame = isPlaying();
}

void Player::buyHPPotion(int* price) {
    if (this->pay(HP_POTION_PRICE)){
        this->heal(POTION_HEAL);
    }
    else {
        *price = 0;
        printMerchantInsufficientCoins(std::cout);
    }
}

void Player::buyBoostPotion(int* price) {
    if (this->pay(BOOST_POTION_PRICE)){
        this->buff(BOOST_BUFF);
    }
    else {
        *price = 0;
        printMerchantInsufficientCoins(std::cout);
    }
}

