#include <iostream>
#include <stack>
#include <string>
using namespace std;

int main() {
    string str;

    cout << "Enter a string: ";
    getline(cin, str);

    stack<char> s;

    // Push all characters onto the stack
    for (char ch : str) {
        s.push(ch);
    }

    // Pop characters to get the reversed string
    string reversed = "";

    while (!s.empty()) {
        reversed += s.top();
        s.pop();
    }

    cout << "Reversed string: " << reversed << endl;

    return 0;
}