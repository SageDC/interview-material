#include <iostream>
#include <unordered_set>
using namespace std;

class Node {
    public:
        Node* next;
        int data;
        Node(int d) {
            data = d;
            next = NULL;
        }
};

void appendToTail(Node** head_ref, int new_data) {
    Node* new_node = new Node(new_data);

    // if the linked list is empty, the new node is head
    if(*head_ref == NULL) { 
        *head_ref = new_node;
        return;
    }

    // traverse the linked list until the last element is reached
    Node* last = *head_ref;
    while(last->next != NULL) {
        last = last->next;
    }

    last->next = new_node;
    return;
}

void deleteNode(Node** head_ref, int data) {
    // store head node
    Node* temp = *head_ref;
    Node* prev = NULL;

    // if head node itself holds the key to be deleted
    if (temp != NULL && temp->data == data) {
        *head_ref = temp->next; // changed head
        delete temp;
        return;
    }
    // else search for the key to be deleted, keep track of the previous node as we need to change prev->next
    else {
        while (temp != NULL && temp->data != data) {
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

/*
    Write code to remove duplicates from an unsorted linked list.
    FOLLOW UP
    How would you solve this problem if a temporary buffer is not allowed?
*/
void removeDuplicates(Node** head_ref) {
    unordered_set<int> seen;
    Node* current = *head_ref;
    Node* previous = NULL;
    while(current != NULL) {
        if(seen.find(current->data) != seen.end()) {
            previous->next = current->next;
            delete(current);
        }
        else {
            seen.insert(current->data);
            previous = current;
        }
        current = previous->next;
    }
}

void printList(Node *n) {
    while (n != NULL) {
        cout << n->data << " ";
        n = n->next;
    }
}

int main() {
    Node* head = new Node(12);
    appendToTail(&head, 11);
    appendToTail(&head, 12);
    appendToTail(&head, 21);
    appendToTail(&head, 41);
    appendToTail(&head, 43);
    appendToTail(&head, 21);
    printList(head);
    cout << endl;
    removeDuplicates(&head);
    printList(head);
    return 0;
}