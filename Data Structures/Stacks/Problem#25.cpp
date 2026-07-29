#include <iostream>
using namespace std;

class Stack {
private:
    static const int SIZE = 100; // Fixed size
    int arr[SIZE];
    int top;

public:
    // Constructor
    Stack() {
        top = -1;
    }

    // Check if stack is empty
    bool isEmpty() {
        return top == -1;
    }

    // Check if stack is full
    bool isFull() {
        return top == SIZE - 1;
    }

    // Push an element onto the stack
    void push(int value) {
        if (isFull()) {
            cout << "Stack Overflow\n";
            return;
        }
        arr[++top] = value;
    }

    // Pop an element from the stack
    void pop() {
        if (isEmpty()) {
            cout << "Stack Underflow\n";
            return;
        }
        top--;
    }
}