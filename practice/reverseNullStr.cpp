#include <iostream>
#include <cstring>
using namespace std;

/*
    Implement a function void reverse(char* str) in C or C++ which reverses
    a null-terminated string.
*/

// when using a null terminated string, *var prints the first letter of the 
// array and !*var returns true if the string is empty
void reverse(char* str) {
    if(!*str) {
        return;
    }

    // save the beginning of the string
    char* begin = str;
    
    // point at the last character
    char* end = begin + strlen(str) - 1;
    
    // swap begin and end
    while(begin < end) {
        char c = *begin;
        *begin = *end;
        *end = c;
        begin++;
        end--;
    }
}

int main() {
    char strArr[] = "1point3acres";
    cout << "Before Reverse: " << strArr << endl;
    reverse(strArr);
    cout << "After Reverse: " << strArr << endl;
    return 0;
}