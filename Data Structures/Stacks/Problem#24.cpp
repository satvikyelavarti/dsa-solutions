#include <iostream>
#include <stack>
#include <string>
using namespace std;

bool isBalanced(string str) {
    stack<char> s;

    for (char ch : str) {
        if (ch == '(') {
            s.push(ch);
        }
        else if (ch == ')') {
            if (s.empty()) {
                return false; // Extra closing parenthesis
            }
            s.pop();
        }
    }

    return s.empty(); // True only if all opening parentheses are matched
}

int main() {
    string str;

    cout << "Enter parentheses string: ";
    cin >> str;

    if (isBalanced(str))
        cout << "Balanced" << endl;
    else
        cout << "Not Balanced" << endl;

    return 0;
}