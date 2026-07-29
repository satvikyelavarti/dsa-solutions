#include <iostream>
using namespace std;

class CircularQueue {
private:
    int arr[5];
    int front;
    int rear;
    int size;

public:
    CircularQueue() {
        front = -1;
        rear = -1;
        size = 5;
    }

    bool isEmpty() {
        return front == -1;
    }

    bool isFull() {
        return (rear + 1) % size == front;
    }

    void enqueue(int value) {
        if (isFull()) {
            cout << "Queue Overflow\n";
            return;
        }

        // First element
        if (isEmpty()) {
            front = rear = 0;
        }
        else {
            rear = (rear + 1) % size;
        }

        arr[rear] = value;
    }

    void dequeue() {
        if (isEmpty()) {
            cout << "Queue Underflow\n";
            return;
        }

        cout << "Deleted: " << arr[front] << endl;

        // Last element removed
        if (front == rear) {
            front = rear = -1;
        }
        else {
            front = (front + 1) % size;
        }
    }

    void peek() {
        if (isEmpty()) {
            cout << "Queue is Empty\n";
        }
        else {
            cout << "Front Element: " << arr[front] << endl;
        }
    }

    void display() {
        if (isEmpty()) {
            cout << "Queue is Empty\n";
            return;
        }

        int i = front;

        while (true) {
            cout << arr[i] << " ";

            if (i == rear)
                break;

            i = (i + 1) % size;
        }

        cout << endl;
    }
};

int main() {
    CircularQueue q;

    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(30);
    q.enqueue(40);
    q.enqueue(50);

    q.display();

    q.dequeue();
    q.dequeue();

    q.display();

    q.enqueue(60);
    q.enqueue(70);

    q.display();

    q.peek();

    return 0;
}