#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;

    Node(int val) {
        data = val;
        next = NULL;
    }
};

void insert(Node*& head, int val) {

    Node* newNode = new Node(val);

    if(head == NULL) {
        head = newNode;
        return;
    }

    Node* temp = head;

    while(temp->next != NULL)
        temp = temp->next;

    temp->next = newNode;
}

void display(Node* head) {

    while(head != NULL) {
        cout << head->data << " ";
        head = head->next;
    }

    cout << endl;
}
Node* reverse(Node* head) {

    Node* prev = NULL;
    Node* curr = head;
    Node* nextNode = NULL;

    while(curr != NULL) {
        nextNode = curr->next;
        curr->next = prev;
        prev = curr;
        curr = nextNode;
    }

    return prev;
}
bool isPalindrome(Node* head) {

    if(head == NULL || head->next == NULL)
        return true;

    Node* slow = head;
    Node* fast = head->next;

    // Find middle
    while(fast != NULL && fast->next != NULL) {
        slow = slow->next;
        fast = fast->next->next;
    }

    // For odd length, skip middle element
    if(fast != NULL)
        slow = slow->next;

    // Reverse second half
    Node* secondHalf = reverse(slow);

    Node* firstHalf = head;

    // Compare both halves
    while(secondHalf != NULL) {

        if(firstHalf->data != secondHalf->data)
            return false;

        firstHalf = firstHalf->next;
        secondHalf = secondHalf->next;
    }

    return true;
}

int main() {

    Node* head = NULL;

    insert(head, 1);
    insert(head, 2);
    insert(head, 3);
    insert(head, 2);
    insert(head, 1);

    display(head);

    if(isPalindrome(head))
        cout << "Palindrome\n";
    else
        cout << "Not Palindrome\n";

    return 0;
}

//Time Complexity = 0(N)
//Space Complexity = 0(1)