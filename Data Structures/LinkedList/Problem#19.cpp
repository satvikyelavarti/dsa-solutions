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

    if (head == NULL) {
        head = newNode;
        return;
    }

    Node* temp = head;
    while (temp->next != NULL)
        temp = temp->next;

    temp->next = newNode;
}

void display(Node* head) {
    while (head != NULL) {
        cout << head->data << " ";
        head = head->next;
    }
    cout << endl;
}

// Merge two sorted lists
Node* mergingSortedLists(Node* head1, Node* head2) {

    if (head1 == NULL) return head2;
    if (head2 == NULL) return head1;

    Node* head = NULL;
    Node* temp = NULL;

    if (head1->data <= head2->data) {
        head = temp = head1;
        head1 = head1->next;
    }
    else {
        head = temp = head2;
        head2 = head2->next;
    }

    while (head1 != NULL && head2 != NULL) {

        if (head1->data <= head2->data) {
            temp->next = head1;
            head1 = head1->next;
        }
        else {
            temp->next = head2;
            head2 = head2->next;
        }

        temp = temp->next;
    }

    if (head1 != NULL)
        temp->next = head1;
    else
        temp->next = head2;

    return head;
}

// Find middle node
Node* getMiddle(Node* head) {

    if (head == NULL)
        return NULL;

    Node* slow = head;
    Node* fast = head->next;

    while (fast != NULL && fast->next != NULL) {
        slow = slow->next;
        fast = fast->next->next;
    }

    return slow;
}

// Merge Sort
Node* mergeSort(Node* head) {

    if (head == NULL || head->next == NULL)
        return head;

    Node* middle = getMiddle(head);
    Node* secondHalf = middle->next;

    middle->next = NULL;   // Split list into two halves

    Node* left = mergeSort(head);
    Node* right = mergeSort(secondHalf);

    return mergingSortedLists(left, right);
}

int main() {

    Node* head = NULL;

    insert(head, 4);
    insert(head, 2);
    insert(head, 1);
    insert(head, 5);
    insert(head, 3);

    cout << "Original List: ";
    display(head);

    head = mergeSort(head);

    cout << "Sorted List: ";
    display(head);

    return 0;
}