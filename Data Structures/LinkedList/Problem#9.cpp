//Printing all values in a linked list
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

    void DisplayNodeValue()
    {
        Node* Temporary = head;
        while (Temporary != NULL)   //Here we run the loop until its not equal to null  and not Temporary->next != NULL because we want the last nodes value as well  
        {
            cout << Temporary->data << "->";
            Temporary = Temporary->next;
        }
        
    }

}