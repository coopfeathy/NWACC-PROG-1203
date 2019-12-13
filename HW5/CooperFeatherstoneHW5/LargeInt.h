//
// Created by Featherstone, Cooper P. (Student) on 2019-10-29.
//

#include <vector>

using namespace std;

class LargeInt {
private:
    vector<int> num;
public:
    LargeInt(vector<int> n);
    LargeInt(string n);
    LargeInt add(LargeInt n);
    string toString();
    vector<int> toVector();
};
