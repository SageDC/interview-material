#include <iostream>
#include <string>
using namespace std;

void reverse(char* str) {
    int size = sizeof(str)/sizeof(str[0]);
    cout << size << endl;
}

int main() {
    char str[] = "hi";
    reverse(str);
    return 0;
}