#include <iostream>
#include <climits>

using namespace std;

// Define the structure for the tree node
struct Node {
    int data;
    Node* left;
    Node* right;
    Node(int val) : data(val), left(NULL), right(NULL) {}
};

class Solution {
public:
    Node* prev;
    Node* first;
    Node* middle;
    Node* last;

    // Function to perform in-order traversal and detect swapped nodes
    void inorder(Node* root) {
        if (!root) return;

        inorder(root->left);

        if (prev != NULL && (root->data < prev->data)) {
            if (!first) {
                first = prev;
                middle = root;
            } else {
                last = root;
            }
        }
        prev = root;

        inorder(root->right);
    }

    // Function to correct the BST by swapping the wrong nodes
    Node* correctBST(Node* root) {
        first = middle = last = NULL;
        prev = new Node(INT_MIN);
        inorder(root);

        if (first && last) {
            swap(first->data, last->data);
        } else if (first && middle) {
            swap(first->data, middle->data);
        }

        return root;
    }
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

    Solution sol;
    root = sol.correctBST(root);

    cout << "Inorder Traversal of the corrected tree: ";
    inorderPrint(root);
    cout << endl;

    return 0;
}
