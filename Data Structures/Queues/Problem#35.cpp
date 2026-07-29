#include <iostream>
#include <queue>
using namespace std;

int countElements(queue<int> q) {
    int count = 0;

    while (!q.empty()) {
        count++;
        q.pop();
    }

    return count;
}

int main() {
    queue<int> q;

    q.push(10);
    q.push(20);
    q.push(30);
    q.push(40);

    cout << "Number of elements = "
         << countElements(q) << endl;

    cout << "Front element still = "
         << q.front() << endl;

    return 0;
}




