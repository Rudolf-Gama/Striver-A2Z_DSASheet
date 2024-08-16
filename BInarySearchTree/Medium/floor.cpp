#include <iostream>
using namespace std;

// Definition for a binary tree node.
struct Node {
    int data;
    Node* left;
    Node* right;
    Node(int x) : data(x), left(NULL), right(NULL) {}
};

// Function to find the floor value in a BST.
int floor(Node* root, int x) {
    if (root == NULL) return -1;
    int Floor = -1;
    while (root) {
        if (root->data == x) {
            Floor = root->data;
            return Floor;
        }
        if (root->data > x) {
            root = root->left;
        } else {
            Floor = root->data;
            root = root->right;
        }
    }
    return Floor;
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
    int floorValue = floor(root, value);
    if (floorValue != -1) {
        cout << "Floor value of " << value << " is " << floorValue << endl;
    } else {
        cout << "No floor value found for " << value << endl;
    }

    value = 0;
    floorValue = floor(root, value);
    if (floorValue != -1) {
        cout << "Floor value of " << value << " is " << floorValue << endl;
    } else {
        cout << "No floor value found for " << value << endl;
    }

    return 0;
}
