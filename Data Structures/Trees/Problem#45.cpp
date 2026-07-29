#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = right = nullptr;
    }
};

int countLeaves(Node* root) {
    // Empty tree
    if (root == nullptr)
        return 0;

    // Leaf node
    if (root->left == nullptr && root->right == nullptr)
        return 1;

    // Count leaves in left and right subtrees
    return countLeaves(root->left) + countLeaves(root->right);
}

int main() {
   
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->right = new Node(6);

    cout << "Number of leaf nodes = "
         << countLeaves(root);

    return 0;
}