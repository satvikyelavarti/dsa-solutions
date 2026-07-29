#include <iostream>
#include <queue>
using namespace std;

int main() {
    int N;
    cout << "Enter N: ";
    cin >> N;

    queue<int> q;

    // Generate counting numbers
    for (int i = 1; i <= N; i++) {
        q.push(i);
    }

    // Print numbers
    cout << "Sequence: ";
    while (!q.empty()) {
        cout << q.front() << " ";
        q.pop();
    }

    return 0;
}