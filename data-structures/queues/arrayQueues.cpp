#include <iostream>
using namespace std;

class Queue {
    public:
        int front, rear, size;
        unsigned capacity;
        int* array;
};

// function to create a queue of given capacity
Queue* createQueue(unsigned capacity) {
    Queue* queue = new Queue();
    queue->capacity = capacity;
    queue->front = queue->size = 0;
    queue->rear = capacity - 1;
    queue->array = new int[queue->capacity];
    return queue;
}

// queue is full when size becomes equal to the capacity
int isFull(Queue* queue) {
    return (queue->size == queue->capacity);
}

// queue is emty when size is 0
int isEmpty(Queue* queue) {
    return (queue->size == 0);
}

// function to add an item to the queue
void enqueue(Queue* queue, int item) {
    if(isFull(queue))
        return;
    queue->rear = (queue->rear + 1) % queue->capacity;
    queue->array[queue->rear] = item;
    queue->size = queue->size + 1;
    cout << item << " enqueued to queue" << endl;
}

// function to remove an item from queue
int dequeue(Queue* queue) {
    if(isEmpty(queue))
        return INT_MIN;
    int item = queue->array[queue->front];
    queue->front = (queue->front + 1) % queue->capacity;
    queue->size = queue->size - 1;
    return item;
}

// function to get fron of queue
int front(Queue* queue) {
    if(isEmpty(queue))
        return INT_MIN;
    return queue->array[queue->front];
}

// function to get rear of queue
int rear(Queue* queue) {
    if(isEmpty(queue))
        return INT_MIN;
    return queue->array[queue->rear];
}

int main() {
    Queue* queue = createQueue(1000);

    enqueue(queue, 10);
    enqueue(queue, 20);
    enqueue(queue, 30);
    enqueue(queue, 40);

    cout << dequeue(queue) << " dequeue from queue" << endl;
    cout << "Front item is " << front(queue) << endl;
    cout << "Rear item is " << rear(queue) << endl;

    return 0;
}