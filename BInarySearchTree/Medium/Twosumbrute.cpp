#include <iostream>
#include <vector>

using namespace std;

// Define the structure for the tree node
struct Node {
    int data;
    Node* left;
    Node* right;
    Node(int val) : data(val), left(NULL), right(NULL) {}
};

// Function to perform in-order traversal and store the result in a vector
void inorder(Node* root, vector<int> &arr) {
    if (root == NULL) return;
    inorder(root->left, arr);
    arr.push_back(root->data);
    inorder(root->right, arr);
}

// Function to check if there is a pair with the given target sum in the BST
int isPairPresent(Node* root, int target) {
    if (!root) return 0;
    vector<int> arr;
    inorder(root, arr);
    int i = 0, j = arr.size() - 1;
    while (i < j) {
        if (arr[i] + arr[j] == target) return 1;
        else if (arr[i] + arr[j] < target) i++;
        else j--;
    }
    return 0;
}

// Utility function to insert a new node in the BST
Node* insert(Node* node, int key) {
    if (node == NULL) return new Node(key);
    if (key < node->data)
        node->left = insert(node->left, key);
    else if (key > node->data)
        node->right = insert(node->right, key);
    return node;
}

int main() {
    Node* root = NULL;
    root = insert(root, 15);
    root = insert(root, 10);
    root = insert(root, 20);
    root = insert(root, 8);
    root = insert(root, 12);
    root = insert(root, 16);
    root = insert(root, 25);

    int target = 28;
    if (isPairPresent(root, target))
        cout << "Pair found" << endl;
    else
        cout << "No pair found" << endl;

    return 0;
}
