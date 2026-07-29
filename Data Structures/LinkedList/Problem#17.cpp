//Merging two sorted linked lists into a single linked list
#include<iostream>
using namespace std;
struct Node{
    int data;
    Node* next;
    Node(int val){
        data = val;
        next = NULL;
    }
};


void display(Node* head) {
    while (head != NULL) {
        cout << head->data << " ";
        head = head->next;
    }
    cout << endl;
}


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

Node* mergingSortedLists(Node* head1, Node* head2) {

    if(head1 == NULL) return head2;
    if(head2 == NULL) return head1;

    Node* head = NULL;
    Node* temp = NULL;

    if(head1->data <= head2->data) {
        temp = head1;
        head1 = head1->next;
    }
    else {
        temp = head2;
        head2 = head2->next;
    }

    head = temp;

    while (true) {
        if (head1->data <= head2->data){
            temp->next = head1;
            head1 = head1->next;
            temp = temp->next;
            //cout << "step 1: " << endl ;
        }
        else{
            temp->next = head2;
            head2 = head2->next;
            temp = temp->next;
            //cout << "step 2: " << endl ;
        }

        if (head1 == NULL){
            temp->next = head2;
            //cout << "step 3: " << endl ;
            break;
        }
        if (head2 == NULL){
            temp->next = head1;
            //cout << "step 4: " << endl ;
            break;
        }
    }

    return head;
}
int main() {
    
    Node* head1 = NULL;
    Node* head2 = NULL;

    insert(head1, 0);
    insert(head1, 1);
    insert(head1, 1);
    insert(head1, 2);
    insert(head1, 3);
    insert(head1, 3);
    insert(head1, 45);

    insert(head2, 2);
    insert(head2, 4);
    insert(head2, 6);

    cout << "List 1: ";
    display(head1);

    cout << "List 2: ";
    display(head2);

    Node* merged = mergingSortedLists(head1, head2);

    cout << "Merged List: ";
    display(merged);

    return 0;
}