#include <iostream>
using namespace std;

struct Node {
    int data;
    struct Node* left;
    struct Node* right;

    // val is the key or value that has to be added to the data part
    Node(int val) {
        data = val;
        // left and right child for node will be initialized to NULL
        left = NULL;
        right = NULL;
    }
};

int main() {
    struct Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    return 0;
}