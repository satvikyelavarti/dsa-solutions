//Reversing a singly linked list using iteration and recursion 

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

class LinkedList {
private:
    Node* head;

public:
    LinkedList() {
        head = NULL;
    }
    void insert(int val) {

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

void display() {
 Node* temp = head;

        while (temp != NULL) {
            cout << temp->data << " -> ";
            temp = temp->next;
        }

        cout << "NULL" << endl;
    }
//Using Iteration
Node* reverseusingIteration() {

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
// Using Recursion
Node* reverseUsingRecursion(Node* curr, Node* prev = NULL) {
    if(curr == NULL)
        return prev;

    Node* nextNode = curr->next;

    curr->next = prev;

    return reverseUsingRecursion(nextNode, curr);
}
};

int main() {

    LinkedList list ;

    list.insert(1);
    list.insert(2);
    list.insert(3);
    list.insert(4);

    cout << "Original: ";
    list.display();

     reverseusingiteration();

    cout << "Reversed: ";
    list.display();
}

//For iterative method
//Time Complexity = 0(N)
//Space Complexity = 0(1)

//For recursive method
//Time Complexity = 0(N)
//Space Complexity = 0(1)
