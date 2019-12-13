//
// Created by Featherstone, Cooper P. (Student) on 2019-10-29.
//

#include <string>
#include <iostream>
#include "LargeInt.h"

//Using namespace std
using namespace std;

//object for LargInt
LargeInt::LargeInt(vector<int> n) {
    num = n;
}


LargeInt::LargeInt(string n) {
    num = vector<int>(n.length());

    for (int i = 0; i < n.length() ; i++) {
        num[i] = stoi(n.substr(n.length() - i - 1, 1));
    }
}

//Turning LargeInt into a string
string LargeInt::toString() {
    string str;

    for (int i = 0; i < num.size(); i++) {
        str = to_string(num[i]) + str;
    }

    return str;
}

// Turning it into a vector
vector<int> LargeInt::toVector() {
    return num;
}

// adding the variables
LargeInt LargeInt::add(LargeInt n) {
    vector<int> num1 = num;
    vector<int> num2 = n.toVector();
    vector<int> newNum = vector<int>(max(num1.size(), num2.size()));

    for (int i = 0; i < num1.size() || i < num2.size(); i++) {
        int x = newNum[i];

        if (i < num1.size()) {
            x += num1[i];
        }

        if (i < num2.size()) {
            x += num2[i];
        }

        newNum[i] = x % 10;
        newNum[i+1] = x / 10;
    }

    return LargeInt(newNum);
}
