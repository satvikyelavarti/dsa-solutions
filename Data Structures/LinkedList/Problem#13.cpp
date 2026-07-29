//Implementing a doubly linked list with insertion and deletion.

#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* prev;
    Node* next;

    Node(int val) {
        data = val;
        prev = NULL;
        next = NULL;
    }
};

class DoublyLinkedList {
private:
    Node* head;
    Node* tail;

public:
    DoublyLinkedList() {
        head = NULL;
        tail = NULL;
    }

    // Insert at Head
    void insertHead(int val) {
        Node* newNode = new Node(val);

        if (head == NULL) {
            head = tail = newNode;
            return;
        }

        newNode->next = head;
        head->prev = newNode;
        head = newNode;
    }

    // Insert at Tail
    void insertTail(int val) {
        Node* newNode = new Node(val);

        if (tail == NULL) {
            head = tail = newNode;
            return;
        }

        tail->next = newNode;
        newNode->prev = tail;
        tail = newNode;
    }

    // Delete at Head
    void deleteHead() {
        if (head == NULL) {
            cout << "List is empty\n";
            return;
        }

        Node* temp = head;

        if (head == tail) {
            head = tail = NULL;
        } else {
            head = head->next;
            head->prev = NULL;
        }

        delete temp;
    }

    // Delete at Tail
    void deleteTail() {
        if (tail == NULL) {
            cout << "List is empty\n";
            return;
        }

        Node* temp = tail;

        if (head == tail) {
            head = tail = NULL;
        } else {
            tail = tail->prev;
            tail->next = NULL;
        }

        delete temp;
    }

    void display() {
    Node* temp = head;

    while (temp != NULL) {
        cout << temp->data << " <-> ";
        temp = temp->next;
    }

    cout << "NULL" << endl;
}

};
int main() {
    DoublyLinkedList dll;

    dll.insertHead(20);
    dll.insertHead(10);
    dll.insertTail(30);
    dll.insertTail(40);

    cout << "List: ";
    dll.display();

    dll.deleteHead();
    cout << "After deleting head: ";
    dll.display();

    dll.deleteTail();
    cout << "After deleting tail: ";
    dll.display();

    return 0;
}



//Time Complexity = 0(N)
//Space Complexity = 0(1)