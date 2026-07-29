//Implementing A single Linked List with insert,delete,search and display
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

    void InsertAtStart(int val) {
        Node* temp = new Node(val);
        temp->next = head;
        head = temp;
    }

    void InsertAtEnd(int val) {
        Node* temp = new Node(val);

        if (head == NULL) {
            head = temp;
            return;
        }

        Node* curr = head;
        while (curr->next != NULL) {
            curr = curr->next;
        }

        curr->next = temp;
    }

    void InsertAtPosition(int pos, int val) {
        if (pos < 1) {
            cout << "Invalid Position\n";
            return;
        }

        if (pos == 1) {
            InsertAtStart(val);
            return;
        }

        Node* curr = head;

        for (int i = 1; i < pos - 1 && curr != NULL; i++) {
            curr = curr->next;
        }

        if (curr == NULL) {
            cout << "Invalid Position\n";
            return;
        }

        Node* temp = new Node(val);
        temp->next = curr->next;
        curr->next = temp;
    }

    void DeleteFromStart() {
        if (head == NULL) {
            cout << "List is empty\n";
            return;
        }

        Node* temp = head;
        head = head->next;
        delete temp;
    }

    void DeleteAtEnd() {
        if (head == NULL) {
            cout << "List is empty\n";
            return;
        }

        if (head->next == NULL) {
            delete head;
            head = NULL;
            return;
        }

        Node* curr = head;

        while (curr->next->next != NULL) {
            curr = curr->next;
        }

        delete curr->next;
        curr->next = NULL;
    }

    void DeleteAtPosition(int pos) {
        if (head == NULL || pos < 1) {
            cout << "Invalid Position\n";
            return;
        }

        if (pos == 1) {
            DeleteFromStart();
            return;
        }

        Node* curr = head;

        for (int i = 1; i < pos - 1  && curr != NULL; i++) {
            curr = curr->next;
        }

        if (curr == NULL || curr->next == NULL) {
            cout << "Invalid Position\n";
            return;
        }

        Node* temp = curr->next;
        curr->next = temp->next;
        delete temp;
    }

    bool SearchTargetElement(int target) {
        Node* temp = head;

        while (temp != NULL) {
            if (temp->data == target)
                return true;

            temp = temp->next;
        }

        return false;
    }

    void Display() {
        Node* temp = head;

        while (temp != NULL) {
            cout << temp->data << " -> ";
            temp = temp->next;
        }

        cout << "NULL" << endl;
    }
};

int main() {
    LinkedList list;

    list.InsertAtStart(10);
    list.InsertAtStart(5);
    list.InsertAtEnd(20);
    list.InsertAtEnd(30);

    cout << "Initial List: ";
    list.Display();

    list.InsertAtPosition(3, 15);
    cout << "After inserting 15 at position 3: ";
    list.Display();

    if (list.SearchTargetElement(20))
        cout << "20 found in the list.\n";
    else
        cout << "20 not found in the list.\n";

    list.DeleteFromStart();
    cout << "After deleting from start: ";
    list.Display();

    list.DeleteAtEnd();
    cout << "After deleting from end: ";
    list.Display();

    list.DeleteAtPosition(2);
    cout << "After deleting position 2: ";
    list.Display();

    return 0;
}



//Time Complexity = 0(N)
//Space Complexity = 0(1)