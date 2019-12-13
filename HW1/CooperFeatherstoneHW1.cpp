// Cooper Featherstone Homework 1
#include <iostream>
#include <cmath>
using namespace std;

int main() {
    // declaring variables
    double a, b, c, right = 0;
    bool triangle = false;


    while(!triangle) {
        //getting input for the first side
        cout << "Enter first side: ";
        cin >> a;

        // making sure the first side is within the parameters
        while ((a < 0.1 || a > 100)) {
            cout << "Invalid first side." << endl;
            cout << "Re-enter first side: ";
            cin >> a;
        }

        // getting input for the second side
        cout << "Enter second side: ";
        cin >> b;

        // making sure the second side is within the parameters
        while ((b < 0.1 || b > 100)) {
            cout << "Invalid second side." << endl;
            cout << "Re-enter second side: ";
            cin >> b;
        }

        // getting input for the third side
        cout << "Enter third side: ";
        cin >> c;

        // making sure the third side is within the parameters
        while ((c < 0.1 || c > 100)) {
            cout << "Invalid third side." << endl;
            cout << "Re-enter third side: ";
            cin >> c;
        }

        // find largest side and store it in the variable c
        if (a > b && a > c) {
            double i = a;
            a = c;
            c = i;
        } else if (b > a && b > c) {
            double i = b;
            b = c;
            c = i;
        }

        // checking to see if the variables add up to be a triangle
        if((a + b) > c){
            triangle = true;
        }else{
            triangle = false;
            cout << "Try again, this is not a triangle." << endl << endl;
        }
    }

    // finding the expected hypotenuse
    right = sqrt((a*a)+(b*b));

    // new line
    cout << endl;

    // outputting the hypotenuse
    cout << "The length of the hypotenuse is " << c << endl << endl;

    // telling the user whether or not the triangle is a right triangle
    cout << "This triangle is" << ((right == c) ? "" : " not") << " a right triangle" << endl;

    return 0;
}

