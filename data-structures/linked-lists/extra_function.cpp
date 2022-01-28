#include <iostream>
using namespace std;

class node {
    public:
        int data;
        node* next;
};

void fun1(struct node* head) {
    if (head == NULL) {
        return;
    }
    fun1(head->next);
    printf("%d ", head->data);
}

/* head_ref is a double pointer which points to head (or start) pointer 
  of linked list */
static void reverse(struct node** head_ref)
{
    struct node* prev   = NULL;
    struct node* current = *head_ref;
    struct node* next;
    while (current != NULL)
    {
        next  = current->next;  
        current->next = prev;   
        prev = current;
        current = next;
    }
    *head_ref = prev;
}

void fun(struct node* start)
{
  if(start == NULL)
    return;
  printf("%d  ", start->data); 
  
  if(start->next != NULL )
    fun(start->next->next);
  printf("%d  ", start->data);
}

int main() {
    return 0;
}