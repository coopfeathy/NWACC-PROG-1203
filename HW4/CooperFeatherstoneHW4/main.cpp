#include <iostream>
#include "Phrase.h"

using namespace std;

int main() {
    while (true) {

        // Defining variables
        string str;
        int choice;

        // Prompting the user to input any string
        cout << "Enter any string: ";
        getline(cin, str);
        Phrase phrase = Phrase(str);

        // Do this forever
        while (true) {

            // outputting the different options ad prompting the user to choose one
            cout << endl;
            cout << "Enter 1 to reverse the string" << endl;
            cout << "Enter 2 to sort the words in the string" << endl;
            cout << "Enter 3 to use rot-13 cipher on the string" << endl;
            cout << "Enter 4 to translate string to pig latin" << endl;
            cout << "Enter 5 to enter another word" << endl;
            cout << "Enter 6 to exit" << endl;
            cout << endl;
            cout << "Your Choice: ";

            // Saving the users input into the variable choice
            cin >> choice;

            // get rid of invalid characters
            if(!cin) {
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
            }

            cout << endl;

            // Outputting the string adapted to the users choice
            if (choice == 1) {
                cout << "Your String Reversed: " << phrase.reverse().get() << endl;
            } else if (choice == 2) {
                cout << "Your String Sorted: " << phrase.sort().get() << endl;
            } else if (choice == 3) {
                cout << "Your String Converted to Rot-13 Cipher: " << phrase.ROT13().get() << endl;
            } else if (choice == 4) {
                cout << "Your String in Pig Latin: " << phrase.pigLatin().get() << endl;
            } else if (choice == 5) {

                getline(cin, str);
                break;
            } else if (choice == 6) {
                return 0;
            }
        }
    }
}
