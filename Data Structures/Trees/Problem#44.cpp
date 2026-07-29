#include <iostream>
using namespace std;

class BST {
private:
    struct Node {
        int data;
        Node* left;
        Node* right;

        Node(int val) {
            data = val;
            left = right = nullptr;
        }
    };

    Node* root;

public:
    BST() {
        root = nullptr;
    }

    
    void insert(int value) {
        Node* newNode = new Node(value);

        if (root == nullptr) {
            root = newNode;
            return;
        }

        Node* current = root;
        Node* parent = nullptr;

        while (current != nullptr) {
            parent = current;

            if (value < current->data)
                current = current->left;
            else if (value > current->data)
                current = current->right;
            else
                return; 
        }

        if (value < parent->data)
            parent->left = newNode;
        else
            parent->right = newNode;
    }

    
    bool search(int value) {
        Node* current = root;

        while (current != nullptr) {
            if (current->data == value)
                return true;

            if (value < current->data)
                current = current->left;
            else
                current = current->right;
        }

        return false;
    }
};

int main() {
    BST tree;

    tree.insert(50);
    tree.insert(30);
    tree.insert(70);
    tree.insert(20);
    tree.insert(40);
    tree.insert(60);
    tree.insert(80);

    cout << tree.search(40) << endl;   // 1
    cout << tree.search(100) << endl;  // 0

    return 0;
}