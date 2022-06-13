#include <cstdlib>
#include <ctime>
#include <iostream>
#include "Die.h"

Die::Die(int dieType) {
    this->dieType = dieType;
}

void Die::setDieType(int dieType) {
    this->dieType = dieType;
}

int Die::getDieType() {
    return this->dieType;
}

void Die::setDieValue(int dieValue) {
    this->dieValue = dieValue;
}

int Die::getDieValue() {
    return this->dieValue;
}

int Die::rollDie() {
    // https://stackoverflow.com/a/20201185
    struct timespec ts;
    clock_gettime(CLOCK_MONOTONIC, &ts);
    /* using nano-seconds instead of seconds */
    srand((time_t)ts.tv_nsec);

    int roll = rand() % dieType + 1;
    return roll;
}
