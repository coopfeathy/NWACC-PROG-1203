#include <iostream>
#include "LargeInt.h"

using namespace std;
//Using namespace std

int main() {

    //Defining variables
    LargeInt bignum1 = LargeInt("10000000000000000000000000000000000000000000000001");
    LargeInt bignum2 = LargeInt("9999999999999999999999999999999999999999999999999");
    LargeInt bignumsum = bignum1.add(bignum2);
    bool running = true;


    // giving the users an exsample
    cout << "This program adds very large unsigned integers." << endl;
    cout << "For example: " << bignum1.toString() << " + " << bignum2.toString() << " === " << bignumsum.toString() << endl;
    cout << endl;

    //getting the users input for the first number
    while (running) {
        cout << "Enter the first number, or 'stop' to quit: ";
        string num;
        string num2;
        cin >> num;

        // The output... if stop is entered, then quit the program
        if (num == "stop") {
            running = false;
        } else {
            // getting the input for the second number
            cout << "Enter the second number: ";
            cin >> num2;
            cout << endl;

            try {
                cout << "Your Numbers added together: " << LargeInt(num).add(LargeInt(num2)).toString() << endl;
                cout << endl;
            } catch(invalid_argument e) {   // catching invalid input.
                cout << "*Invalid input*" << endl;
                cout << endl;
            }
        }
    }

    return 0;
}
