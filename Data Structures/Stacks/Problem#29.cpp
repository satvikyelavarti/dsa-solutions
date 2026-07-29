#include <iostream>
using namespace std;

class Stack {
    int arr[100];
    int top;

public:
    Stack() {
        top = -1;
    }

    bool isEmpty() {
        return top == -1;
    }

    bool isFull() {
        return top == 99;
    }

    void push(int x) {
        if (isFull()) {
            cout << "Stack Overflow\n";
            return;
        }
        arr[++top] = x;
    }

    int pop() {
        if (isEmpty()) {
            cout << "Stack Underflow\n";
            return -1;
        }
        return arr[top--];
    }

    int peek() {
        if (isEmpty())
            return -1;
        return arr[top];
    }

    void display() {
        for (int i = top; i >= 0; i--)
            cout << arr[i] << " ";
        cout << endl;
    }
};

// Insert an element into its correct sorted position
void sortedInsert(Stack &st, int x) {
    if (st.isEmpty() || st.peek() <= x) {
        st.push(x);
        return;
    }

    int temp = st.pop();
    sortedInsert(st, x);
    st.push(temp);
}

// Sort stack recursively
void sortStack(Stack &st) {
    if (st.isEmpty())
        return;

    int temp = st.pop();

    sortStack(st);

    sortedInsert(st, temp);
}

int main() {
    Stack st;

    st.push(30);
    st.push(5);
    st.push(18);
    st.push(14);
    st.push(3);

    cout << "Original Stack (top to bottom): ";
    st.display();

    sortStack(st);

    cout << "Sorted Stack (top to bottom): ";
    st.display();

    return 0;
}