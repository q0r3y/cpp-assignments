/*
* CIS-115-DS
* Author: q0r3y
*
* Create a program that simulates the roll of a die.
* Have the program output the rolls of six dice repeatedly
* until at least four of the dice roll the same number.
* Allow user to select die dieType.
*
*/

#include <iostream>
#include <vector>
#include <cstdlib>
#include <unordered_map>
#include "Die.h"

using std::cout;
using std::endl;
using std::cin;
using std::vector;
using std::unordered_map;

/*
 * Accepts a vector array of Die objects
 * Checks the roll value of each Die and returns a boolean
 * which indicates if there were 4 or more matches in the array.
 */
bool checkRolls(vector<Die> &diceArray) {
    int val = 2;
    unordered_map<int, int> occurrences;

    for (Die &die : diceArray) {
        occurrences[die.getDieValue()]++;
    }

    unordered_map<int, int>::iterator it = occurrences.begin();
    while (it != occurrences.end()) {
        if (it->second >= 4) {
            cout << "\n\n " << it->first << " has occurred: " << it->second << " times." << endl;
            return true;
        }
        it++;
    }
    return false;
}

/*
 * Accepts an integer as a die type and returns a vector array of 6 Die objects
 */
vector<Die> createDieArray(int dieType) {
    vector<Die> diceArray;
    const int NUM_OF_DIE = 6;

    for (int i = 1; i <= NUM_OF_DIE; ++i) {
        diceArray.push_back(Die(dieType));
    }
    return diceArray;
}

// Needs to validate input
int setDieType() {
    int dieType;

    cout << "\n Please select a die type: ";
    while (!(cin >> dieType) || dieType < 0) {
        cout << " Error: Please input a positive integer: ";
        cin.clear();
        cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    }
    return dieType;
}

/*
 * Accepts a vector of Die objects and rolls each die in the array.
 */
void rollDice(vector<Die> &diceArray) {
    cout << endl;
    for (Die &die : diceArray) {
        int roll {die.rollDie()};
        cout << " [" << roll << "] ";
        die.setDieValue(roll);
    }
}

int main() {
    bool fourMatchingRolls = false;
    int dieType {setDieType()};
    int rollAttempt = 0;

    while (!fourMatchingRolls) {
        rollAttempt++;
        vector<Die> diceArray {createDieArray(dieType)};
        rollDice(diceArray);
        if (checkRolls(diceArray)) {
            cout << " It took " << rollAttempt << " roll attempts to get 4 or more matches." << endl;
            fourMatchingRolls = true;
        }
    }

    // https://stackoverflow.com/a/24776299
    cout << "\n (Right now the program is waiting for input because there's really no good way to stop this window from closing when it is finished running)" << endl;
    cin >> rollAttempt;
    return 0;
}
