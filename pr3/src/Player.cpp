/*
 * CIS-115-DS
 * Author: q0r3y
 *
 * Player class for Pig Dice Game
 *
 */

#include <string>
#include "Player.h"

using std::string;

Player::Player(string name) {
    this->name = name;
    this->roll = 0;
    this->totalPoints = 0;
    this->turnPoints = 0;
}

void Player::setName(string name) {
    this->name = name;
}

string Player::getName() {
    return this->name;
}

void Player::setTotalPoints(int points) {
    this->totalPoints = points;
}

int Player::getTotalPoints() {
    return this->totalPoints;
}

void Player::setTurnPoints(int points) {
    this->turnPoints = points;
}

int Player::getTurnPoints() {
    return this->turnPoints;
}

void Player::setCurrentRoll(int value) {
    this->roll = value;
}

int Player::getCurrentRoll() const {
    return roll;
}


