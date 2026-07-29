//Finding middle element of a linked list
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

// Display linked list
void display(Node* head) {

    while(head != NULL) {
        cout << head->data << " ";
        head = head->next;
    }

    cout << endl;
}

// Find middle node
Node* findMiddle(Node* head) {

    if(head == NULL)
        return NULL;

    Node* slow = head;
    Node* fast = head->next;

    while(fast != NULL && fast->next != NULL) {
        slow = slow->next;
        fast = fast->next->next;
    }

    return slow;
}

int main() {

    Node* head = NULL;

    insert(head, 1);
    insert(head, 2);
    insert(head, 3);
    insert(head, 4);
   

    cout << "Linked List: ";
    display(head);

    Node* middle = findMiddle(head);

    cout << "Middle Element: " << middle->data << endl;

    return 0;
}

//Time Complexity = 0(N)
//Space Complexity = 0(1)