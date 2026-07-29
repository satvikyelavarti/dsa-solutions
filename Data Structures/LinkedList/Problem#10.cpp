//Findind the target element in a linked list
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
    bool SearchTargetElement (int target)
    {
        Node* Temporary = head;
        while (Temporary != NULL)
        {
            if(Temporary->data == target)
                return true;
            Temporary = Temporary->next;
        }
        return false;
    }
}