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

    while(temp->next)
        temp = temp->next;

    temp->next = newNode;
}

void display(Node* head) {

    while(head) {
        cout << head->data << " ";
        head = head->next;
    }

    cout << endl;
}

bool detectLoop(Node* head) {

    Node* slow = head;
    Node* fast = head;

   while(fast != NULL && fast->next != NULL) {
        slow = slow->next;
        fast = fast->next->next;
        if(slow == fast)
            return true;
    }

    return false;
}

void removeLoop(Node* head) {

    Node* slow = head;
    Node* fast = head;
    
    while(fast != NULL && fast->next != NULL) {
        slow = slow->next;
        fast = fast->next->next;

        if(slow == fast)
            break;
    }
     slow = head;

    while(slow != fast) {
        slow = slow->next;
        fast = fast->next;
    }

    Node* temp = slow;

    while(temp->next != slow)
        temp = temp->next;

    temp->next = NULL;
}


//Time Complexity = 0(N)
//Space Complexity = 0(1)