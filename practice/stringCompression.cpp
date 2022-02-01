#include <iostream>
#include <string>
using namespace std;

/* Problem:
    Implement a method to perform basic string compression using the counts
    of repeated characters. For example, the string aabcccccaaa would become
    a2b1c5a3. If the "compressed" string would not become smaller than the
    original string, your method should return the original string.
*/

/* My solution */
string strCompression(string original) {
    int originalLength = original.length();
    string compressedStr = "";
    char begin = original[0];
    int charCount = 0;
    // O(n) where n is the length of the original string
    for(int i = 1; i < originalLength; i++) {
        charCount++;
        if(begin != original[i] || i == originalLength - 1) {
            // string concatenation operates in O(n^2) time
            compressedStr = compressedStr + begin + to_string(charCount);
            begin = original[i];
            charCount = 0;
        }
    }

    if(compressedStr.length() < originalLength) {
        return compressedStr;
    }
    return original;
}

/* Authors solution */


int main() {
    cout << "Compressed string: " << strCompression("aabcccccaaa") << endl;
    return 0;
}