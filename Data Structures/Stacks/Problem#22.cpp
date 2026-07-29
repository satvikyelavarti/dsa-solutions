//Implementing a stack class using a fixed size C++ array.
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

    // Return the top element
    int peek() {
        if (isEmpty()) {
            cout << "Stack is Empty\n";
            return -1;
        }
        return arr[top];
    }

    // Display stack elements
    void display() {
        if (isEmpty()) {
            cout << "Stack is Empty\n";
            return;
        }

        for (int i = top; i >= 0; i--) {
            cout << arr[i] << " ";
        }
        cout << endl;
    }
};

int main() {
    Stack s, s1;

    s.push(10);
    s.push(20);
    s.push(30);
    s1.push(100);
    
    cout << "Top element: " << s.peek() << endl;
    cout << "Top element: " << s1.peek() << endl;
        s.display();
        s1.display();
    s.pop();

    cout << "After pop:\n";
    s.display();

    return 0;
}