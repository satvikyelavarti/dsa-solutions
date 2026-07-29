#include <iostream>
#include <queue>
using namespace std;

int main() {
    queue<string> customers;

    // Customers arrive
    customers.push("Satvik");
    customers.push("Arjun");
    customers.push("Ajay");
    customers.push("Ram");

    cout << "Customers waiting in line:\n";
    queue<string> temp = customers;
    while (!temp.empty()) {
        cout << temp.front() << endl;
        temp.pop();
    }

    while (!customers.empty()) {
        cout << "Now serving: " << customers.front() << endl;
        customers.pop();
    }

    cout << "\nNo customers left in the queue.\n";

    return 0;
}