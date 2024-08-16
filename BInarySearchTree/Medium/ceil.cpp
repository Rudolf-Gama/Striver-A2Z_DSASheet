#include <iostream>
using namespace std;

// Definition for a binary tree node.
struct Node {
    int data;
    Node* left;
    Node* right;
    Node(int x) : data(x), left(NULL), right(NULL) {}
};

// Function to find the ceiling value in a BST.
int findCeil(Node* root, int input) {
    if (root == NULL) return -1;
    int Ceil = -1;
    while (root) {
        if (root->data == input) {
            Ceil = root->data;
            return Ceil;
        }
        if (root->data > input) {
            Ceil = root->data;
            root = root->left;
        } else {
            root = root->right;
        }
    }
    return Ceil;
}

// Helper function to insert a new node in the BST.
Node* insert(Node* root, int val) {
    if (root == NULL) {
        return new Node(val);
    }
    if (val < root->data) {
        root->left = insert(root->left, val);
    } else {
        root->right = insert(root->right, val);
    }
    return root;
}

// Helper function to print the BST in inorder traversal.
void inorder(Node* root) {
    if (root != NULL) {
        inorder(root->left);
        cout << root->data << " ";
        inorder(root->right);
    }
}

int main() {
    Node* root = NULL;
    root = insert(root, 4);
    insert(root, 2);
    insert(root, 7);
    insert(root, 1);
    insert(root, 3);
    insert(root, 6);
    insert(root, 8);

    cout << "Inorder traversal of the BST: ";
    inorder(root);
    cout << endl;

    int value = 5;
    int ceilValue = findCeil(root, value);
    if (ceilValue != -1) {
        cout << "Ceiling value of " << value << " is " << ceilValue << endl;
    } else {
        cout << "No ceiling value found for " << value << endl;
    }

    value = 9;
    ceilValue = findCeil(root, value);
    if (ceilValue != -1) {
        cout << "Ceiling value of " << value << " is " << ceilValue << endl;
    } else {
        cout << "No ceiling value found for " << value << endl;
    }

    return 0;
}
