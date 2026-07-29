#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;
    int height;

    Node(int val) {
        data = val;
        left = right = NULL;
        height = 1;
    }
};

int maxHeight(int a, int b) {
    return (a > b) ? a : b;
}

int getHeight(Node* node) {
    if (node == NULL)
        return 0;
    return node->height;
}

int getBalance(Node* node) {
    if (node == NULL)
        return 0;

    return getHeight(node->left) - getHeight(node->right);
}

// Right Rotation (LL)
Node* rightRotate(Node* y) {
    Node* x = y->left;
    Node* T2 = x->right;

    x->right = y;
    y->left = T2;

    y->height = 1 + maxHeight(getHeight(y->left),
                              getHeight(y->right));

    x->height = 1 + maxHeight(getHeight(x->left),
                              getHeight(x->right));

    return x;
}

// Left Rotation (RR)
Node* leftRotate(Node* x) {
    Node* y = x->right;
    Node* T2 = y->left;

    y->left = x;
    x->right = T2;

    x->height = 1 + maxHeight(getHeight(x->left),
                              getHeight(x->right));

    y->height = 1 + maxHeight(getHeight(y->left),
                              getHeight(y->right));

    return y;
}

Node* insert(Node* root, int key) {

    // Normal BST insertion
    if (root == NULL)
        return new Node(key);

    if (key < root->data)
        root->left = insert(root->left, key);

    else if (key > root->data)
        root->right = insert(root->right, key);

    else
        return root;   // duplicate not allowed

    // Update height
    root->height = 1 + maxHeight(getHeight(root->left),
                                 getHeight(root->right));

    int balance = getBalance(root);

    // LL Case
    if (balance > 1 && key < root->left->data)
        return rightRotate(root);

    // RR Case
    if (balance < -1 && key > root->right->data)
        return leftRotate(root);

    // LR Case
    if (balance > 1 && key > root->left->data) {
        root->left = leftRotate(root->left);
        return rightRotate(root);
    }

    // RL Case
    if (balance < -1 && key < root->right->data) {
        root->right = rightRotate(root->right);
        return leftRotate(root);
    }

    return root;
}



int main() {
    Node* root = NULL;

    root = insert(root, 10);
    root = insert(root, 20);
    root = insert(root, 30);
    root = insert(root, 40);
    root = insert(root, 50);
    root = insert(root, 25);

  

    return 0;
}