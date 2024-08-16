#include <iostream>
#include <climits>  // For INT_MIN and INT_MAX
#include <algorithm> // For min and max functions

using namespace std;

// Definition for a binary tree node
class Node {
public:
    int data;
    Node* left;
    Node* right;

    Node(int value) {
        data = value;
        left = right = nullptr;
    }
};

// Helper class to store minimum, maximum, and size of the largest BST subtree
class NodeValue {
public:
    int mini;
    int maxi;
    int size;

    NodeValue(int mini, int maxi, int size) {
        this->mini = mini;
        this->maxi = maxi;
        this->size = size;
    }
};

class Solution {
public:
    // Helper function to determine the largest BST subtree
    NodeValue bst(Node* root) {
        if (!root) return NodeValue(INT_MAX, INT_MIN, 0);  // Corrected the initial values

        auto left = bst(root->left);
        auto right = bst(root->right);

        if (left.maxi < root->data && right.mini > root->data) {
            return NodeValue(min(root->data, left.mini), max(root->data, right.maxi), left.size + right.size + 1);
        }
        return NodeValue(INT_MAX, INT_MIN, max(left.size, right.size));  // Corrected the returned values
    }

    // Main function to return the size of the largest BST subtree
    int largestBst(Node* root) {
        if (!root) return 0;
        return bst(root).size;
    }
};

// Helper function to insert nodes in the binary tree for testing
Node* insert(Node* root, int data) {
    if (!root) {
        return new Node(data);
    }

    if (data < root->data) {
        root->left = insert(root->left, data);
    } else {
        root->right = insert(root->right, data);
    }

    return root;
}

// Main function to test the solution
int main() {
    Solution sol;
    Node* root = nullptr;

    // Construct the binary tree
    root = insert(root, 50);
    root = insert(root, 30);
    root = insert(root, 60);
    root = insert(root, 5);
    root = insert(root, 20);
    root = insert(root, 45);
    root = insert(root, 70);
    root = insert(root, 65);
    root = insert(root, 80);

    cout << "Size of the largest BST is: " << sol.largestBst(root) << endl;

    return 0;
}
