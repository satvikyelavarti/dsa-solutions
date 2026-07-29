#include <iostream>
#include <queue>
#include <stack>
using namespace std;

bool isPalindrome(queue<int> q) {
    stack<int> s;

    // Push all queue elements into stack
    queue<int> temp = q;
    while (!temp.empty()) {
        s.push(temp.front());
        temp.pop();
    }

    // Compare queue front with stack top
    while (!q.empty()) {
        if (q.front() != s.top()) {
            return false;
        }

        q.pop();
        s.pop();
    }

    return true;
}

int main() {
    queue<int> q;

    q.push(1);
    q.push(2);
    q.push(3);
    q.push(2);
    q.push(1);

    if (isPalindrome(q))
        cout << "Queue is a palindrome";
    else
        cout << "Queue is not a palindrome";

    return 0;
}