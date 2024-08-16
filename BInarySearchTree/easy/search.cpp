#include <iostream>
using namespace std;

// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

// Function to search in a Binary Search Tree (BST).
TreeNode* searchBST(TreeNode* root, int val) {
    while (root != NULL && root->val != val) {
        root = root->val > val ? root->left : root->right;
    }
    return root;
}

// Helper function to insert a new node in the BST.
TreeNode* insert(TreeNode* root, int val) {
    if (root == NULL) {
        return new TreeNode(val);
    }
    if (val < root->val) {
        root->left = insert(root->left, val);
    } else {
        root->right = insert(root->right, val);
    }
    return root;
}

// Helper function to print the BST in inorder traversal.
void inorder(TreeNode* root) {
    if (root != NULL) {
        inorder(root->left);
        cout << root->val << " ";
        inorder(root->right);
    }
}

int main() {
    TreeNode* root = NULL;
    root = insert(root, 4);
    insert(root, 2);
    insert(root, 7);
    insert(root, 1);
    insert(root, 3);
    
    cout << "Inorder traversal of the BST: ";
    inorder(root);
    cout << endl;

    int value = 2;
    TreeNode* result = searchBST(root, value);
    if (result != NULL) {
        cout << "Found node with value " << value << endl;
    } else {
        cout << "Node with value " << value << " not found" << endl;
    }

    value = 5;
    result = searchBST(root, value);
    if (result != NULL) {
        cout << "Found node with value " << value << endl;
    } else {
        cout << "Node with value " << value << " not found" << endl;
    }

    return 0;
}
