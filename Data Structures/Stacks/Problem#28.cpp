#include <iostream>
#include <stack>
#include <string>
using namespace std;

int evaluatePostfix(string postfix) {
    stack<int> st;

    for (char ch : postfix) {

        // Operand (single digit)
        if (isdigit(ch)) {
            st.push(ch - '0');
        }

        // Operator
        else {
            int operand2 = st.top();
            st.pop();

            int operand1 = st.top();
            st.pop();

            switch (ch) {
                case '+':
                    st.push(operand1 + operand2);
                    break;

                case '-':
                    st.push(operand1 - operand2);
                    break;

                case '*':
                    st.push(operand1 * operand2);
                    break;

                case '/':
                    st.push(operand1 / operand2);
                    break;
            }
        }
    }

    return st.top();
}

int main() {
    string postfix;

    cout << "Enter postfix expression: ";
    cin >> postfix;

    cout << "Result = " << evaluatePostfix(postfix) << endl;

    return 0;
}