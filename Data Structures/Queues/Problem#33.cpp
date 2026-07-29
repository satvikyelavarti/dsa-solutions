#include <iostream>
using namespace std;

class Queue {
    int arr[100];
    int front, rear;

public:
    Queue() {
        front = rear = -1;
    }

    bool isEmpty() {
        return front == -1;
    }

    bool isFull() {
        return rear == 99;
    }

    void enqueue(int x) {
        if (isFull()) {
            cout << "Queue Overflow\n";
            return;
        }

        if (isEmpty()) {
            front = rear = 0;
        }
        else {
            rear++;
        }

        arr[rear] = x;
    }

    int dequeue() {
        if (isEmpty()) {
            cout << "Queue Underflow\n";
            return -1;
        }

        int value = arr[front];

        // Last element being removed
        if (front == rear) {
            front = rear = -1;
        }
        else {
            front++;
        }

        return value;
    }

    int peek() {
        if (isEmpty()) {
            cout << "Queue is Empty\n";
            return -1;
        }

        return arr[front];
    }
};

int main() {
    Queue q;

    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(30);

    cout << "Front element: " << q.peek() << endl;

    cout << "Dequeued: " << q.dequeue() << endl;
    cout << "Dequeued: " << q.dequeue() << endl;

    cout << "Front element: " << q.peek() << endl;

    return 0;
}