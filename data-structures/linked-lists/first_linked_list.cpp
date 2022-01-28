// A simple CPP program to introduce a linked list
#include <iostream>
using namespace std;

class Node {
    public:
        int data;
        Node* next;
};

/* Given a reference (pointer to pointer) to the head of a list and an int, inserts a new node on the fronmt of the list */
// Time complexity: O(1) as it does a constant amount of work
void push(Node** head_ref, int new_data) {
    // 1. allocate the new node 
    Node* new_node = new Node();
    // 2. put in the data
    new_node->data = new_data;
    // 3. make next of new node as head
    new_node->next = (*head_ref);
    // 4. move the head to point to the new node
    (*head_ref) = new_node;
}

/* Given a node prev_node, insert a new node after the given prev_node */
// Time complexity: O(1) as it does a constant amount of work
void insertAfter(Node* prev_node, int new_data) {
    // 1.) Check if the given prev_node is NULL
    if (prev_node == NULL) {
        cout << "The given previous node cannot be NULL";
        return;
    }
    // 2.) allocate the new node
    Node* new_node = new Node();
    // 3.) Put in the data
    new_node->data = new_data;
    // 4.) Make next of new node as next of prev_node
    new_node->next = prev_node->next;
    // 5.) move the next of prev_node as new_node
    prev_node->next = new_node;
}

/* Given a reference (pointer to pointer) to the head of a list and an int, appends a new node at the end */
// Time complexity: O(n) but can be optimized to O(1) by keep an extra pointer for the tail of the linked list
void append(Node** head_ref, int new_data) {
    // 1. allocate node
    Node* new_node = new Node();
    // 2. Put in the data
    new_node->data = new_data;
    // 3. This new node is going to be the last node, so make next of it as NULL
    new_node->next = NULL;
    // 4. If the linked list is empty, then make the new node as head
    if (*head_ref == NULL) {
        *head_ref = new_node;
        return;
    }
    // 5. Else traverse till the last node
    Node* last = *head_ref;
    while (last->next != NULL) {
        last = last->next;
    }
    // 6. Change the next of last node
    last->next = new_node;
    return;
}

// this function prints contents of linked list starting from the given node
void printList(Node *n) {
    while (n != NULL) {
        cout << n->data << " ";
        n = n->next;
    }
}

// Program to create a simple linked list with 3 nodes
int main() {
    /* Start with the empty list */
    Node *head = NULL;

    // Linked list becomes 6->NULL
    append(&head, 6);

    // 7 added to beginning: linked list becomes 7->6->NULL
    push(&head, 7);

    // 1 added to beginning: linked list becomes 1->7->6->NULL
    push(&head, 1);

    // 4 inserted at the end: linked list becomes 1->7->6->4->NULL
    append(&head, 4);

    // 8 inserted after 7: linked list becomes 1->7->8->6->4->NULL
    insertAfter(head->next, 8);

    cout << "Created linked list is: ";
    printList(head);
    
    return 0;
}