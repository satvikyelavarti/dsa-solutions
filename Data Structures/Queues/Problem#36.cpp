#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;

    Node(int val) {
        data = val;
        next = NULL;
    }
};

class Queue {
    Node* front;
    Node* rear;

public:
    Queue() {
        front = rear = NULL;
    }

    bool isEmpty() {
        return front == NULL;
    }

    void enqueue(int x) {
        Node* newNode = new Node(x);

        if (rear == NULL) {
            front = rear = newNode;
            return;
        }

        rear->next = newNode;
        rear = newNode;
    }

    int dequeue() {
        if (isEmpty()) {
            cout << "Queue Underflow\n";
            return -1;
        }

        Node* temp = front;
        int value = temp->data;

        front = front->next;

        if (front == NULL)
            rear = NULL;

        delete temp;
        return value;
    }

    int peek() {
        if (isEmpty()) {
            cout << "Queue is Empty\n";
            return -1;
        }

        return front->data;
    }

    void display() {
        Node* temp = front;

        while (temp != NULL) {
            cout << temp->data << " ";
            temp = temp->next;
        }

        cout << endl;
    }
};

int main() {
    Queue q;

    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(30);

    cout << "Queue: ";
    q.display();

    cout << "Front element: " << q.peek() << endl;

    cout << "Dequeued: " << q.dequeue() << endl;

    cout << "Queue after dequeue: ";
    q.display();

    return 0;
}