//
// Created by Featherstone, Cooper P. (Student) on 2019-12-12.
//

#include "Word.h"
#include <regex>
#include <iostream>

using namespace std;

Word::Word() {

}

Word::Word(string n, int line) {
    cleanWord(n);

    word = n;
    lines.push_back(line);
}

bool Word::add(string n, int line) {
    cleanWord(n);

    if ((n == word) == 1) {
        lines.push_back(line);

        return true;
    }

    return false;
}

void cleanWord(string& n) {
    transform(n.begin(), n.end(), n.begin(), ::tolower);

    regex reg("^[^a-z]+");

    n = regex_replace(n, reg, "");

    reg = regex("[^a-z]+$");
    n = regex_replace(n, reg, "");
}

string Word::toString() {
    string out = word + "(" + to_string(lines.size()) + ")" + ": ";

    for (int i = 0 ; i < lines.size(); i++) {
        out += to_string(lines[i]);

        if (i < lines.size() - 1) {
            out += ", ";
        }
    }

    return out;
}

int Word::count() {
    return lines.size();
}