//
// Created by Featherstone, Cooper P. (Student) on 2019-12-12.
//

#ifndef COOPERFEATHERSTONEHW8_CONCORDANCE_H
#define COOPERFEATHERSTONEHW8_CONCORDANCE_H

#include <vector>
#include <fstream>
#include <map>
#include "Word.h"

using namespace std;

class Concordance {
private:
    map<string, Word> words;
public:
    Concordance(ifstream file);
    string toString();
};

#endif //COOPERFEATHERSTONEHW8_CONCORDANCE_H
