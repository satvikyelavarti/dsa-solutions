
#include <iostream>
using namespace std;

class Deque {
    int arr[100];
    int front, rear;
    int size;

public:
    Deque(int s) {
        size = s;
        front = -1;
        rear = -1;
    }

    bool isEmpty() {
        return front == -1;
    }

    bool isFull() {
        return rear == size - 1;
    }

    void insertRear(int x) {
        if (isFull()) {
            cout << "Deque Overflow\n";
            return;
        }

        if (isEmpty()) {
            front = rear = 0;
        } else {
            rear++;
        }

        arr[rear] = x;
    }

    void insertFront(int x) {
        if (isFull()) {
            cout << "Deque Overflow\n";
            return;
        }

        if (isEmpty()) {
            front = rear = 0;
            arr[front] = x;
            return;
        }

        // Shift elements right
        for (int i = rear; i >= front; i--) {
            arr[i + 1] = arr[i];
        }

        arr[front] = x;
        rear++;
    }

    void deleteFront() {
        if (isEmpty()) {
            cout << "Deque Underflow\n";
            return;
        }

        // Shift elements left
        for (int i = front; i < rear; i++) {
            arr[i] = arr[i + 1];
        }

        rear--;

        if (rear < front) {
            front = rear = -1;
        }
    }

    void deleteRear() {
        if (isEmpty()) {
            cout << "Deque Underflow\n";
            return;
        }

        rear--;

        if (rear < front) {
            front = rear = -1;
        }
    }

    int getFront() {
        if (isEmpty()) {
            cout << "Deque is Empty\n";
            return -1;
        }

        return arr[front];
    }

    int getRear() {
        if (isEmpty()) {
            cout << "Deque is Empty\n";
            return -1;
        }

        return arr[rear];
    }

    void display() {
        if (isEmpty()) {
            cout << "Deque is Empty\n";
            return;
        }

        for (int i = front; i <= rear; i++) {
            cout << arr[i] << " ";
        }
        cout << endl;
    }
};

int main() {
    Deque dq(7);

    dq.insertRear(1);
    dq.insertRear(2);
    dq.insertFront(4);
    dq.insertFront(3);

    cout << "Deque: ";
    dq.display();

    dq.deleteFront();
    dq.deleteRear();

    cout << "After deletion: ";
    dq.display();

    return 0;
}