// Cooper Featherstone Homework 2
#include <iostream>
#include <cmath>
#include <array>
#include <vector>

using namespace std;

// defining variables
string noVowels(string s);
string word;
bool replace(string& str, const string& from, const string& to);
void replaceAll(string& str, const string& from, const string& to);

// main function
int main() {

    // getting user input
    cout << "Input string to remove vowels from: ";
    getline(cin, word);

    //outputting the input with no vowels
    cout << noVowels(word) << endl;

    return 0;
}

// my created function
string noVowels(string s) {

    // string with the vowels that we need to remove
    vector<string> vowels = {"A", "E", "I", "O", "U", "a", "e", "i", "o", "u"};

    // for loop that goes through all the vowels
    for (int i = 0; i < vowels.size(); i++) {
        replaceAll(s, vowels[i], "");
    }

    return s;
}

//the process of taking all the vowels and changing them to nothing
void replaceAll(string& str, const string& from, const string& to) {
    while(replace(str, from, to)) {}
}

bool replace(string& str, const string& from, const string& to) {
    size_t start_pos = str.find(from);
    if (start_pos == string::npos)
        return false;

    str.replace(start_pos, from.length(), to);
    return true;
}