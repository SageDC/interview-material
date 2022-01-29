#include <iostream>
using namespace std;

int binarySearch(int arr[], int low, int high, int x) {
    if(high >= low) {
        int mid = low + (high - low) / 2;
        // return the index if the value is located at mid
        if(arr[mid] == x)
            return mid;

        // if element is less than mid, only using bottom half of list to search
        if(arr[mid] > x) {
            return binarySearch(arr, low, mid - 1, x);
        }

        // if reached this point then x is greater than mid and we use right half of array
        return binarySearch(arr, mid + 1, high, x);
    }
    // if x not in array
    return -1;
}

int main() {
    int arr[] = {2,3,4,10,40};
    int x = 10;
    int n = sizeof(arr)/sizeof(arr[0]);
    int result = binarySearch(arr, 0, n - 1, x);
    (result == -1) ? cout << "Element is not present in array" : cout << "Element is present at index " << result << endl;
    return 0;
}