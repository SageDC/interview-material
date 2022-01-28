// A simple CPP program to introduce a linked list
#include <iostream>
using namespace std;

class Node {
    public:
        int data;
        Node* next;
};

// this function prints contents of linked list starting from the given node
void printList(Node *n) {
    while (n != NULL) {
        cout << n->data << " ";
        n = n->next;
    }
}

// Program to create a simple linked list with 3 nodes
int main() {
    Node* head = NULL;
    Node* second = NULL;
    Node* third = NULL;

    // allocate 3 nodes in the heap
    head = new Node();
    second = new Node();
    third = new Node();

    head->data = 1; // assign data in the first node
    head->next = second; // link the first node with the second

    second->data = 2; // assign data to the second node
    second->next = third; // link second node with the third node

    third->data = 3; // assign data to the third node
    third->next = NULL;

    printList(head);
    
    return 0;
}