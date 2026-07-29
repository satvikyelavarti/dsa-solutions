#include <iostream>
using namespace std;

class TwoStacks {
    int arr[100];
    int top1, top2;

public:
    TwoStacks() {
        top1 = -1;
        top2 = 100;
    }

    // Push into Stack 1
    void push1(int x) {
        if (top1 + 1 == top2) {
            cout << "Stack Overflow\n";
            return;
        }

        arr[++top1] = x;
    }

    // Push into Stack 2
    void push2(int x) {
        if (top1 + 1 == top2) {
            cout << "Stack Overflow\n";
            return;
        }

        arr[--top2] = x;
    }

    // Pop from Stack 1
    int pop1() {
        if (top1 == -1) {
            cout << "Stack 1 Underflow\n";
            return -1;
        }

        return arr[top1--];
    }

    // Pop from Stack 2
    int pop2() {
        if (top2 == 100) {
            cout << "Stack 2 Underflow\n";
            return -1;
        }

        return arr[top2++];
    }

    // Peek Stack 1
    int peek1() {
        if (top1 == -1)
            return -1;
        return arr[top1];
    }

    // Peek Stack 2
    int peek2() {
        if (top2 == 100)
            return -1;
        return arr[top2];
    }
};

int main() {
    TwoStacks ts;

    ts.push1(10);
    ts.push1(20);
    ts.push1(30);

    ts.push2(100);
    ts.push2(200);
    ts.push2(300);

    cout << "Top of Stack 1: " << ts.peek1() << endl;
    cout << "Top of Stack 2: " << ts.peek2() << endl;

    cout << "Popped from Stack 1: " << ts.pop1() << endl;
    cout << "Popped from Stack 2: " << ts.pop2() << endl;

    return 0;
}