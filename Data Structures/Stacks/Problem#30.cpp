#include <iostream>
using namespace std;

class SpecialStack {
    int st[100];
    int minSt[100];

    int top1;
    int top2;

public:
    SpecialStack() {
        top1 = top2 = -1;
    }

    void push(int x) {
        st[++top1] = x;

        if (top2 == -1 || x <= minSt[top2]) {
            minSt[++top2] = x;
        }
    }

    void pop() {
        if (top1 == -1) {
            cout << "Stack Underflow\n";
            return;
        }

        int x = st[top1--];

        if (x == minSt[top2]) {
            top2--;
        }
    }

    int getMin() {
        if (top2 == -1) {
            cout << "Stack Empty\n";
            return -1;
        }
        return minSt[top2];
    }

    int peek() {
        if (top1 == -1)
            return -1;
        return st[top1];
    }
};

int main() {
    SpecialStack s;

    s.push(18);
    s.push(19);
    s.push(29);
    s.push(15);
    s.push(16);

    cout << "Minimum = " << s.getMin() << endl;


   