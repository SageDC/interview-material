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

/* Check if ith bit is set in the binary form of the given number
   - AND the number N with the number 2^i
   - 2^i contains a single bit set to 1
   - If the ith bit is set to 1 then the AND will return 2^i, else it returns 0
   - We can write 2^i as i << 1 */
bool check(int N) {
    int i = 2;
    if(N & (1 << i))
        return true;
    else
        return false;
}

/* Print possible subsets
   - 2^N possible subsets of any given set with N elements
   - We represent each element in the subset with a bit
   - Can be used to determine if an element belongs to a subset
   - If A = {a, b, c} and all present then {111} */
void possibleSubsets(char A[], int N) {
    for(int i = 0; i < (1 << N); ++i) {
        for(int j = 0; j < N; ++j) {
            if(i & (1 << j))
                cout << A[j] << ' ';
        }
        cout << endl;
    }
}

int main() {
    // Returns 1 if true
    // cout << isPowerOfTwo(16) << endl;
    
    // cout << count_one(3) << endl;

    // cout << check(20) << endl;

    char arr[] = {'a', 'b', 'c', 'd'};
    possibleSubsets(arr, 3);
    return 0;
}