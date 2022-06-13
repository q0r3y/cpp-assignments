/*
 * CIS-115-DS
 * Author: q0r3y
 *
 * Roll the dice to see who goes first.  Highest role of the die is the first player.
 * When a Pig player takes their turn, they can roll the dice as many times as they want.
 * Scoring is simple – whatever the number of dots show up on the dice, that’s your points for the roll.
 * You keep rolling and accumulating the points.  If you roll a 3, then a 5, then a 2,
 * and then a 6 your points so far would be 3 + 5 + 2 + 6 = 16.
 * If one of the dice is a 1, no points are added to the overall score and your turn is over.
 * But, if BOTH the dice show up as 1’s your entire score goes back to zero (0), your turn is over,
 * and you pass the dice to the other player.
 * In 2-Dice Pig, doubles score higher. Just add up the dice value and double it.
 * Rolling two 2’s = (2 + 2) x 2 = 8.  Rolling two 5’s = (5 + 5) x 2 = 20.  The same for 3’s, 4’s, and 6’s.
 * First player to 500 wins!
 */

#include <iostream>
#include "Die.h"
#include "Player.h"
#include <vector>
#include <limits>

using std::cout;
using std::endl;
using std::cin;
using std::vector;
using std::string;

vector<Player> players;
vector<Die> dice {Die(6), Die(6)};
const int WINNING_SCORE = 500;
bool playing {true};
bool rolling {true};

void whoGoesFirst();
void createPlayers();
void rollDice();
void printPlayerStats(Player &player);
bool bothDieOnes();
bool oneDieIsOne();
void setTurnScore(Player &player);
void setTotalScore(Player &player);
bool continueRolling(Player &player);
void checkForWin(Player &player);

int main() {

    createPlayers();
    whoGoesFirst();

    while(playing) {
        for (Player &player : players) {
            if (playing) {
                cout << "\n-------------------------------" << endl;
                cout << player.getName() << "'s turn." << endl;
                rolling = true;
                player.setTurnPoints(0);
                while (rolling) {
                    printPlayerStats(player);
                    rollDice();
                    if (!bothDieOnes()) {
                        if (!oneDieIsOne()) {
                            setTurnScore(player);
                            printPlayerStats(player);
                            if(!continueRolling(player)) {
                                setTotalScore(player);
                                checkForWin(player);
                                rolling = false;
                            }
                        } else {
                            rolling = false;
                        }
                    } else {
                        player.setTotalPoints(0);
                        rolling = false;
                    }
                }
            }
        }
    }

    return 0;
}

void whoGoesFirst() {
    cout << endl;
    while (players[0].getCurrentRoll() == players[1].getCurrentRoll()) {
        for (Player &player : players) {
            int roll = dice[0].rollDie();
            player.setCurrentRoll(roll);
            cout << " " << player.getName() << " rolled: " << roll << endl;
        }
    }
    cout << endl;
    if (players[0].getCurrentRoll() > players[1].getCurrentRoll()) {
        cout << players[0].getName() << " goes first." << endl;
    } else {
        cout << players[1].getName() << " goes first." << endl;
        std::swap(players.front(), players.back());
    }
}

void createPlayers() {
    for (int i = 1; i <= 2; ++i) {
        string name;
        cout << "Player "<< i << " please enter your name: ";
        cin >> name;
        players.push_back(Player(name));
    }
}

void rollDice() {
    int i = 1;
    cout << endl;
    for (Die &die : dice) {
        int roll = die.rollDie();
        cout << " - Die"<< i << " rolled: " << roll << endl;
        die.setDieValue(roll);
        i++;
    }
    cout << endl;
}

void printPlayerStats(Player &player) {
    cout << " - " << player.getName() << "'s total points: " << player.getTotalPoints() << endl;
    cout << " - " << player.getName() << "'s turn points: " << player.getTurnPoints() << endl;
}

bool bothDieOnes() {
    if (dice[0].getDieValue() == 1 && dice[1].getDieValue() == 1) {
        cout << "!! Both dice rolled one. Your total score is set to 0, your turn is over.";
        return true;
    }
    return false;
}

bool oneDieIsOne() {
    if (dice[0].getDieValue() == 1 || dice[1].getDieValue() == 1) {
        cout << "! A die rolled a 1. You score no points this turn, your turn is over.";
        return true;
    }
    return false;
}

void setTurnScore(Player &player) {
    int turnScore = player.getTurnPoints();
    for (Die &die : dice) {
        turnScore += die.getDieValue();
    }
    player.setTurnPoints(turnScore);
}

void setTotalScore(Player &player) {
    int totalPoints = player.getTotalPoints();
    int turnPoints = player.getTurnPoints();
    player.setTotalPoints((totalPoints + turnPoints));
}

bool continueRolling(Player &player) {
    char choice;
    do
    {
        cin.clear();
        cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        cout << player.getName() << " would you like to roll again?(y/n): ";
        cin >> choice;
    }
    while (tolower(choice) != 'y' && tolower(choice) !='n');

    if (tolower(choice) == 'y') {
        return true;
    }
    return false;
}

void checkForWin(Player &player) {
    if (player.getTotalPoints() >= WINNING_SCORE) {
        cout << "\n!!!" << player.getName() << "'s score: " << player.getTotalPoints() << "!!!" <<endl;
        cout << "!!! " << player.getName() << " WINS !!!" << endl;
        playing = false;
    }
}






