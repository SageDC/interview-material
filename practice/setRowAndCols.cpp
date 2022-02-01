#include <iostream>
#include <vector>
using namespace std;

int main() {
    int arr[][4] = {{1,1,1,1}, {1,0,1,1}, {1,1,1,0}};

    // Get the size of the matrix
    int rows = sizeof(arr)/sizeof(arr[0]);
    int cols = sizeof(arr[0])/sizeof(int);

    vector<int> rowNums;
    vector<int> colNums;

    // Best we can achieve is O(n^2) to locate zeros
    for(int i = 0; i < rows; i++) {
        for(int j = 0; j < cols; j++) {
            if(arr[i][j] == 0) {
                rowNums.push_back(i);
                colNums.push_back(j);
            }
        }
    }

    // Now that we have the position of zeros, we then set each corresponding row and column to 0
    // Best we can achieve is 0(n^2) because we again have to traverse the entire matrix
    for(int i = 0; i < rowNums.size(); i++) {
        for(int j = 0; j < cols; j++) {
            arr[rowNums[i]][j] = 0;
        }
        for(int j = 0; j < rows; j++) {
            arr[j][colNums[i]] = 0;
        }
    }

    // Just for printing - ignore
    for(int i = 0; i < rows; i++) {
        for(int j = 0; j < cols; j++) {
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}