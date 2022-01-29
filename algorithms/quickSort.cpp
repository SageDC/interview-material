#include <iostream>
using namespace std;

/* Swaps elements */
void swap(int* a, int* b) {
    int t = *a;
    *a = *b;
    *b = t;
}

/* Takes last element as pivot and places the pivot element at its correct position in sorted array */
int partition(int arr[], int low, int high) {
    int pivot = arr[high];
    int index = (low - 1);
    for(int j = low; j <= high - 1; j++) {
        if(arr[j] < pivot) {
            index++;
            swap(&arr[index], &arr[j]);
        }
    }
    swap(&arr[index + 1], &arr[high]);
    return  (index + 1);
}

int quickSort(int arr[], int low, int high) {
    if(low < high) {
        int pi = partition(arr, low, high);
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

void printArray(int arr[], int size) {
    for(int i = 0; i < size; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main() {
    int arr[] = {10, 7, 8, 9, 1, 5};
    int n = sizeof(arr) / sizeof(arr[0]);
    quickSort(arr, 0, n - 1);
    cout << "Sorted array: " << endl;
    printArray(arr, n);
    return 0;
}