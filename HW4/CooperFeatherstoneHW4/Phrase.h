//
// Created by Featherstone, Cooper P. (Student) on 2019-10-11.
//

#include <string>
using namespace std;

class Phrase {
private:
    string phrase;
public:
    Phrase(std::string p);
    std::string get();
    Phrase reverse();
    Phrase sort();
    Phrase ROT13();
    Phrase pigLatin();
};

bool is_vowel(char c);
string pigLatinWord(string s);
vector<string> split(string s, string delimiter);