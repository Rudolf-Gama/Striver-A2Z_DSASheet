#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// Define the structure for the tree node
struct Node {
    int data;
    Node* left;
    Node* right;
    Node(int val) : data(val), left(NULL), right(NULL) {}
};

// Utility function to insert a new node in the BST
Node* insert(Node* node, int key) {
    if (node == NULL) return new Node(key);
    if (key < node->data)
        node->left = insert(node->left, key);
    else if (key > node->data)
        node->right = insert(node->right, key);
    return node;
}

// Function to perform in-order traversal and store the elements in a vector
void storeInOrder(Node* root, vector<int> &inorder) {
    if (root == NULL) return;
    storeInOrder(root->left, inorder);
    inorder.push_back(root->data);
    storeInOrder(root->right, inorder);
}

// Function to correct the BST using a brute force approach
void correctBST(Node* root, vector<int> &sortedInorder, int &index) {
    if (root == NULL) return;
    correctBST(root->left, sortedInorder, index);
    root->data = sortedInorder[index++];
    correctBST(root->right, sortedInorder, index);
}

// Function to print in-order traversal of the BST
void inorderPrint(Node* root) {
    if (!root) return;
    inorderPrint(root->left);
    cout << root->data << " ";
    inorderPrint(root->right);
}

int main() {
    Node* root = NULL;
    root = insert(root, 10);
    root = insert(root, 5);
    root = insert(root, 8);
    root = insert(root, 2);
    root = insert(root, 20);
    root = insert(root, 15);
    root = insert(root, 25);

    // Introducing an error by swapping two nodes
    swap(root->left->data, root->right->data); // Swap 5 and 20 to introduce an error

    cout << "Inorder Traversal of the original tree: ";
    inorderPrint(root);
    cout << endl;

    vector<int> inorder;
    storeInOrder(root, inorder);
    sort(inorder.begin(), inorder.end());
    int index = 0;
    correctBST(root, inorder, index);

    cout << "Inorder Traversal of the corrected tree: ";
    inorderPrint(root);
    cout << endl;

    return 0;
}
