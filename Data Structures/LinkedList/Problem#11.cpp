//Finding the number of nodes in a linked list
#include<iostream>
using namespace std;
struct Node{
    int data;
    Node* next;
    Node(int Val)(
         data = Val;
         next = NULL;
    )
}
class LinkedList{
    Node* head;
    public:
    LinkedList()
    {
        head = NULL
    }
    
    int countNodes()
    {
        int count = 0;

        Node* Temporary = head;

        while(Temporary != NULL)
        {
            count++;
            Temporary = Temporary->next;
        }

        return count;
    }
}

