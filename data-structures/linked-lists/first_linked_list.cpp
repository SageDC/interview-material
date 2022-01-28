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

/* given a reference (pointer to pointer) to the head of a list and a key, deletes the first occurence of key in linked list */
void deleteNode(Node** head_ref, int key) {
    // store head node
    Node* temp = *head_ref;
    Node* prev = NULL;

    // if head node itself holds the key to be deleted
    if (temp != NULL && temp->data == key) {
        *head_ref = temp->next; // changed head
        delete temp;
        return;
    }
    // else search for the key to be deleted, keep track of the previous node as we need to change prev->next
    else {
        while (temp != NULL && temp->data != key) {
            prev = temp;
            temp = temp->next;
        }
        // If key was not present in linked list
        if (temp == NULL) {
            return;
        }
        // unlink the node from linked list
        prev->next = temp->next;
        // free memory
        delete temp;
    }
}

void deleteNodeRec(Node*& head, int key) {
    // check if the list is empty or we reached the end of the list
    if (head == NULL) {
        cout << "Element not present in the list\n";
        return;
    }
    // if current node is the node to be deleted
    if (head->data == key) {
        Node* temp = head;
        // if its start of the node head then the node points to second node
        head = head->next;
        delete(temp);
        return;
    }
    deleteNode(&head->next, key);
}

/* Given a reference (pointer to pointer) to the head of a list and a position,
deletes the node at the given position */
void delNodeAtPos(Node** head_ref, int position) {
    // if linked list is empty
    if (*head_ref == NULL) {
        return;
    }

    // store head node
    Node* temp = *head_ref;

    // if head needs to be removed
    if (position == 0) {
        // change head
        *head_ref = temp->next;

        // free old head
        free(temp);
        return;
    }

    // find previous node of the node to be deleted
    for (int i = 0; temp != NULL && i < position - 1; i++) {
        temp = temp->next;
    }

    // if position is more than number of nodes
    if (temp == NULL || temp->next == NULL) {
        return;
    }

    // Node temp->next is the node to be deleted
    // Store pointer to the next of node to be deleted
    Node* next = temp->next->next;

    // unlink the node from linked list
    free(temp->next);

    // unlink the deleted node from list
    temp->next = next;
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

    // add elements in linked list
    push(&head, 7);
    push(&head, 1);
    push(&head, 3);
    push(&head, 2);
    push(&head, 8);

    puts("Created Linked List: ");
    printList(head);
    delNodeAtPos(&head, 4);
    puts("\nLinked List after deletion at position 4: ");
    printList(head);
    
    return 0;
}