//Inserting A node at the Head of the linked list
#include<iostream>
using namespace std;
struct Node {
    int data;
    Node* next;
    Node(int Val){
        data = Val;
        next = NULL;
    }
}
class LinkedList {
    Node* head;
    public:
        LinkedList()
        {
            head = NULL;
        }
    void InsertAtHead(int val){
            Node* temp = new Node(val);
            temp->next = head;
            head = temp;
        }
}