#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};

Node* findLCA(Node* root, int n1, int n2) {
    while (root != NULL) {

        // Both nodes in left subtree
        if (n1 < root->data && n2 < root->data)
            root = root->left;

        // Both nodes in right subtree
        else if (n1 > root->data && n2 > root->data)
            root = root->right;

        // Split point found
        else
            return root;
    }

    return NULL;
}