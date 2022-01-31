#include <iostream>
using namespace std;

/*  Problem:

    Write a method to replace all spaces in a string with '%20': You may assume that
    the string has sufficient space at the end of the string to hold the additional
    characters, and that you are given the "true" length of the string.

    Examples:
        Input: "Mr%20John%20Smith"
        Output: "Mr%20John%20Smith"
*/

string insertPercentTwenty(string str, int length) {
    string copy = "";
    for(int i = 0; i < length; i++) {
        if(str[i] == ' ') {
            copy.append("%20");
        }
        else {
            copy = copy + str[i];
        }
    }
    return copy;
}

int main() {
    // given true length
    string newStr = insertPercentTwenty("Hello There Darren    ", 18);
    cout << newStr << endl;
    return 0;
}