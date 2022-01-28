#include <iostream>
#include <queue>
using namespace std;

struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};

/* Function to create a new node */
Node* createNode(int data) {
    Node* newNode = new Node();

    if(!newNode) {
        cout << "Memory error" << endl;
        return NULL;
    }

    newNode->data = data;
    newNode->left = newNode->right = NULL;
    return newNode;
}

/* Function to insert into a binary tree */
Node* insertNode(Node* root, int data) {
    // if the tree is empty, create a new node
    if(root == NULL) {
        root = createNode(data);
        return root;
    }

    // else do a level order traversal until we find an empty place
    queue<Node*> q;
    q.push(root);

    while(!q.empty()) {
        Node* temp = q.front();
        q.pop();

        if(temp->left != NULL) {
            q.push(temp->left);
        }
        else {
            temp->left = createNode(data);
            return root;
        }

        if(temp->right != NULL) {
            q.push(temp->right);
        }
        else {
            temp->right = createNode(data);
            return root;
        }
    }
}

/* Inorder traversal of a binary tree */
void inOrder(Node* temp) {
    if(temp == NULL) {
        return;
    }

    inOrder(temp->left);
    cout << temp->data << ' ';
    inOrder(temp->right);
}

int main() {
    Node* root = createNode(10);
    root->left = createNode(11);
    root->left->left = createNode(7);
    root->right = createNode(9);
    root->right->left = createNode(15);
    root->right->right = createNode(8);
    
    cout << "Inorder traversal before insertion: ";
    inOrder(root);
    cout << endl;

    int key = 12;
    root = insertNode(root, key);

    cout << "Inorder traversal after insertion: ";
    inOrder(root);
    cout << endl;

    return 0;
}