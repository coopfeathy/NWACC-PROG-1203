// Cooper Feahterstone Homework 3
#include <iostream>
#include "Number.h"

using namespace std;

int main() {

    // Declaring variables
    long num = 0;

    // do this forever
    while (true) {
        // getting the input from the user
        cout << "Input a number to remove zeros and reverse: ";
        cin >> num;

        // having the user try again if they dont enter a valid number
        while(!cin) {
            cin.clear();
            cin.ignore(numeric_limits < streamsize>::max(), '\n');
            cout << "Invalid number" << endl;
            cout << "Try again: ";
            cin >> num;
        }

        // stop when number is 0
        if (num == 0) break;

        // print the number after all changes are made
        cout << Number(num).stripZeros().reverse().get() << endl;
    }

    return 0;
}
