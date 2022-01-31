#include <iostream>
#include <string>
#include <unordered_map>
using namespace std;

/*
    Given two strings, write a method to decide if one is a permutation of the other.
*/

// a way, especially one of several possible variations, in which a set or number of things 
// can be ordered or arranged.

/* Questions:
    Are the strings case sensitive?
    Is white space signigicant?
*/

// Time complexity: O(n), Space: O(n)
bool isPermutation(string original, string test) {

    if(original.length() != test.length()) {
        return false;
    }

    unordered_map<char, int> characters;
    for(int i = 0; i < original.length(); i++) {
        characters[original[i]]++;  
    }

    for(int i = 0; i < test.length(); i++) {
        characters[test[i]]--;
    }

    for(auto iter = characters.begin(); iter != characters.end(); iter++) {
        if(iter->second != 0) {
            return false;
        }
    }
    return true;
}

int main() {
    cout << isPermutation("hello", "ehlla") << endl;
    return 0;
}