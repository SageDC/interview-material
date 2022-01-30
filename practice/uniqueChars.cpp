#include <iostream>
#include <unordered_set>
#include <string>
using namespace std;

/* Implement an algorithm to determine if a string has all unique
   characters. What if you cannot use additional data structures? */

/* Questions:
    Is the input an ASCII string or unicode string?

    Does capitilization matter?
*/

// unordered_set operations have O(1) best case and O(n) worst case
bool hasUniqueCharacters(string word) {
    unordered_set<char> uniqueChars;
    for(int i = 0; i < word.length(); i++) {
        if(uniqueChars.find(word[i]) != uniqueChars.end()) {
            return false;
        }
        uniqueChars.insert(word[i]);
    }
    return true;
}

// if additional data structures cannot be used then we use the brute force method
// Time complexity: O(n^2)
bool hasUniqueCharacters2(string word) {
    for(int i = 0; i < word.length(); i++) {
        for(int j = 0; j < word.length(); j++) {
            if(i != j && word[i] == word[j]) {
                return false;
            }
        }
    }
    return true;
}


// ASCI char (book solution)
// Time complexity: O(n), Space = O(1)
bool isUniqueChars(string str) {
    if(str.length() > 256) return false;

    bool char_set[256];
    for(int i = 0; i < str.length(); i++) {
        int val = str.at(i);
        if(char_set[val]) {
            return false;
        }
        char_set[val] = true;
    }
    return true;
}

int main() {
    cout << isUniqueChars("the") << endl;
    return 0;
}