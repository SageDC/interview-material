#include <iostream>
using namespace std;

/* Function will return true if x is a power of 2, otherwise false
   Time Complexity: O(logn)
    bool isPowerOfTwo(int x) {
        if(x == 0)
            return false;
        else {
            while(x % 2 == 0) x /= 2;
            return (x == 1);
        }
    }
*/

bool isPowerOfTwo(int x) {
    // x will check if x == 0 and !(x & (x - 1)) will check if x is a power of 2 or not
    return (x && !(x & (x - 1)));
}

/* count 1's in a binary representation of a number
   Time Complexity: Best Case: O(k), Worst Case: O(logn) */
int count_one(int n) {
    int count = 0;
    while(n) {
        n = n & (n - 1);
        count++;
    }
    return count;
}



int main() {
    // Returns 1 if true
    // cout << isPowerOfTwo(16) << endl;
    
    cout << count_one(3) << endl;
    return 0;
}