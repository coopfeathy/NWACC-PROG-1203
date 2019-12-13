//
// Created by Featherstone, Cooper P. (Student) on 2019-12-12.
//

#ifndef COOPERFEATHERSTONEHW8_WORD_H
#define COOPERFEATHERSTONEHW8_WORD_H

#include <string>
#include <vector>

using namespace std;

class Word {
private:
    string word;
    vector<int> lines;
public:
    Word();
    Word(string n, int line);
    bool add(string n, int line);
    int count();
    string toString();
};

void cleanWord(string& n);

#endif //COOPERFEATHERSTONEHW8_WORD_H
