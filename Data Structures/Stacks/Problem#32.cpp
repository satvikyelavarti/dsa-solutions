#include <iostream>
using namespace std;

class Stack {
    char arr[100];
    int top;

public:
    Stack() {
        top = -1;
    }

    void push(char x) {
        arr[++top] = x;
    }

    char pop() {
        return arr[top--];
    }

    bool isEmpty() {
        return top == -1;
    }
};

bool isPalindrome(Stack st) {   // pass by value to preserve original stack
    char str[100];
    int n = 0;

    while (!st.isEmpty()) {
        str[n++] = st.pop();
    }

    int i = 0, j = n - 1;

    while (i < j) {
        if (str[i] != str[j])
            return false;
        i++;
        j--;
    }

    return true;
}

int main() {
    Stack st;

    st.push('R');
    st.push('A');
    st.push('D');
    st.push('A');
    st.push('R');

    if (isPalindrome(st))
        cout << "Palindrome\n";
    else
        cout << "Not Palindrome\n";

    return 0;
}