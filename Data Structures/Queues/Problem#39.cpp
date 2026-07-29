#include <iostream>
#include <queue>
#include <stack>
using namespace std;

void reverseFirstK(queue<int>& q, int k) {
    if (q.empty() || k > q.size() || k <= 0)
        return;

    stack<int> s;

    // Push first k elements into stack
    for (int i = 0; i < k; i++) {
        s.push(q.front());
        q.pop();
    }

    // Enqueue back from stack
    while (!s.empty()) {
        q.push(s.top());
        s.pop();
    }

    // Move remaining elements to the rear
    int remaining = q.size() - k;

    for (int i = 0; i < remaining; i++) {
        q.push(q.front());
        q.pop();
    }
}

void display(queue<int> q) {
    while (!q.empty()) {
        cout << q.front() << " ";
        q.pop();
    }
    cout << endl;
}

int main() {
    queue<int> q;

    for (int i = 1; i <= 7; i++)
        q.push(i);

    cout << "Original Queue: ";
    display(q);

    for (int i = 1; i <= 7; i++)
        q.push(i);

    reverseFirstK(q, 4);

    cout << "After Reversing First 4 Elements: ";
    display(q);

    return 0;
}