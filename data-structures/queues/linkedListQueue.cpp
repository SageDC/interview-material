#include <iostream>
using namespace std;

struct QueueNode {
    int data;
    QueueNode* next;
    QueueNode(int d) {
        data = d;
        next = NULL;
    }
};

struct Queue {
    QueueNode *front, *rear;
    Queue() {
        front = rear = NULL;
    }

    void enqueue(int x) {
        QueueNode* temp = new QueueNode(x);

        if(rear == NULL) {
            front = rear = temp;
            return;
        }

        rear->next = temp;
        rear = temp;
    }

    void dequeue() {
        if(front == NULL)
            return;
        
        QueueNode* temp = front;
        front = front->next;

        if(front == NULL)
            rear = NULL;
        
        delete(temp);
    }
};

int main() {
    Queue q;
    q.enqueue(10);
    q.enqueue(20);
    q.dequeue();
    q.dequeue();
    q.enqueue(30);
    q.enqueue(40);
    q.enqueue(50);
    q.dequeue();
    cout << "Queue Front: " << (q.front)->data << endl;
    cout << "Queue Rear: " << (q.rear)->data;
}