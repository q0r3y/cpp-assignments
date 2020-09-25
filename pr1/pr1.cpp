#include <iostream>
#include <algorithm>

using namespace std;

/*
* CIS-115-DS
* Author: q0r3y
* Generate a lotto ticket with 5 random numbers between 1-69
* Ensures that the numbers are never used more
* than once in that ticket.
*
*/

int main() {

  int intArray[5] = {};
  int min = 1;
  int max = 69;
  int range = max - min + 1;

  // https://stackoverflow.com/a/9459063
  srand((unsigned int)time(NULL));

  for(int i = 0; i <= 4; ++i) {
    int randInt = rand() % range + min;
    for(int value: intArray) {
      while(randInt == value) {
        randInt = rand() % range + min;
      }
    }
    intArray[i] = randInt;
  }

  sort(begin(intArray), end(intArray));

  cout << "Lotto Ticket Number: ";
  for(int randInt: intArray) {
    cout << randInt << " ";
  }
  cout << endl;

  return 0;
}
