//
// Created by Featherstone, Cooper P. (Student) on 2019-12-12.
//

#include "Concordance.h"
#include <istream>
#include <algorithm>
#include <sstream>

using namespace std;

Concordance::Concordance(ifstream file) {
    string line;
    int lineNum = 1;

    while (getline(file, line)) {
        string str;
        istringstream ss(line);

        while (getline(ss, str, ' ')) {
            cleanWord(str);

            if (str == "") {
                continue;
            }

            if (!words.count(str)) {
                words[str] = Word(str, lineNum);
            } else {
                words[str].add(str, lineNum);
            }
        }

        lineNum++;
    }
}

string Concordance::toString() {
    /*sort(words.begin(), words.end(),
              [](auto a, auto b)
              { return a->second.count() > b->second.count();});*/

    string out = "";

    for (auto a : words) {
        out += (a.second).toString() + "\n";
    }

    return out;
}
