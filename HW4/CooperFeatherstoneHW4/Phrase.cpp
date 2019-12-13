//
// Created by Featherstone, Cooper P. (Student) on 2019-10-11.
//

#include "Phrase.h"
#include <vector>

using namespace std;

// constructor
Phrase::Phrase(string p) : phrase(p) {};

// getting the entered string
string Phrase::get() {
    return phrase;
}

Phrase Phrase::reverse() {
    string str = phrase;

    // creating a variable for the sting length
    unsigned long n = str.length();

    // putting the string in reverse
    for (int i = 0; i < n / 2; i++)
        swap(str[i], str[n - i - 1]);

    return Phrase(str);
}

// sort words in phrase
Phrase Phrase::sort() {
    string str = "";

    vector<string> v = split(phrase, " ");

    ::sort(v.begin(), v.end()); // sort words

    for (auto i : v) {
        str += i + " ";
    }

    // Return the sorted words
    return Phrase(str);
}

// rot13 cipher
Phrase Phrase::ROT13() {
    string transformed;
    for (size_t i = 0; i < phrase.size(); ++i) {
        if (isalpha(phrase[i])) {
            if ((tolower(phrase[i]) - 'a') < 14)
                transformed.append(1, phrase[i] + 13);
            else
                transformed.append(1, phrase[i] - 13);
        } else {
            transformed.append(1, phrase[i]);
        }
    }
    return Phrase(transformed);
}

// converting the given string into pig latin
Phrase Phrase::pigLatin() {
    string str = "";

    vector<string> v = split (phrase, " ");

    for (auto i : v) {
        str += pigLatinWord(i) + " ";
    }

    return Phrase(str);
}

// splitting up the string into words
    vector<string> split(string s, string delimiter) {
    size_t pos_start = 0, pos_end, delim_len = delimiter.length();
    string token;
    vector<string> res;

    while ((pos_end = s.find (delimiter, pos_start)) != string::npos) {
        token = s.substr (pos_start, pos_end - pos_start);
        pos_start = pos_end + delim_len;
        res.push_back (token);
    }

    res.push_back (s.substr (pos_start));
    return res;
}

// converting the words in the string to pig latin
string pigLatinWord(string s) {
    string str = s;

    if(is_vowel(str[0])) {
        return str.append("way");
    } else {
        bool upper = false;

        upper = isupper(str[0]);
        if (upper) {
            str[0] = tolower(str[0]);
        }

        str += str[0];
        str.erase(0, 1);

        if (upper) {
            str[0] = toupper(str[0]);
        }

        return str.append("ay");
    }
}

// test if the variable char is a vowel
bool is_vowel(char c) {
    c = tolower(c);
    return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u';
}
