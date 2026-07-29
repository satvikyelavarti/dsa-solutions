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

Node* buildTree(int preorder[], int inorder[],
                int inStart, int inEnd, int& preIndex) {

    // Important base case
    if (inStart > inEnd)
        return NULL;

    Node* root = new Node(preorder[preIndex++]);

    if (inStart == inEnd)
        return root;

    int pos;
    for (int i = inStart; i <= inEnd; i++) {
        if (inorder[i] == root->data) {
            pos = i;
            break;
        }
    }

    root->left = buildTree(preorder, inorder,
                           inStart, pos - 1, preIndex);

    root->right = buildTree(preorder, inorder,
                            pos + 1, inEnd, preIndex);

    return root;
}

void printInorder(Node* root) {
    if (root == NULL)
        return;

    printInorder(root->left);
    cout << root->data << " ";
    printInorder(root->right);
}

int main() {
    int preorder[] = {1, 2, 4, 5, 3, 6};
    int inorder[]  = {4, 2, 5, 1, 6, 3};

    int n = sizeof(preorder) / sizeof(preorder[0]);

    int preIndex = 0;

    Node* root = buildTree(preorder,
                           inorder,
                           0,
                           n - 1,
                           preIndex);

    cout << "Inorder: ";
    printInorder(root);

    return 0;
}