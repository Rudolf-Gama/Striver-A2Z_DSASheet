#include <iostream>
#include <vector>
#include <queue>
using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;
    Node(int val) : data(val), left(NULL), right(NULL) {}
};

// Function to serialize a tree and return a list containing nodes of the tree
vector<int> serialize(Node* root) {
    if (!root) return {};
    vector<int> ans;
    queue<Node*> q;
    q.push(root);
    while (!q.empty()) {
        Node* temp = q.front();
        q.pop();
        if (temp == NULL) {
            ans.push_back(0);  // Use 0 to represent NULL nodes
        } else {
            ans.push_back(temp->data);
            q.push(temp->left);
            q.push(temp->right);
        }
    }
    return ans;
}

// Function to deserialize a list and construct the tree
Node* deSerialize(vector<int>& A) {
    if (A.empty()) return NULL;
    int i = 0;
    int ele = A[i++];
    queue<Node*> q;
    Node* root = new Node(ele);
    q.push(root);
    while (!q.empty()) {
        Node* temp = q.front();
        q.pop();
        
        // Process the left child
        if (i < A.size()) {
            ele = A[i++];
            if (ele == 0) {
                temp->left = NULL;
            } else {
                Node* leftNode = new Node(ele);
                temp->left = leftNode;
                q.push(leftNode);
            }
        }
        
        // Process the right child
        if (i < A.size()) {
            ele = A[i++];
            if (ele == 0) {
                temp->right = NULL;
            } else {
                Node* rightNode = new Node(ele);
                temp->right = rightNode;
                q.push(rightNode);
            }
        }
    }
    return root;
}

// Helper function to print the tree in level order
void printLevelOrder(Node* root) {
    if (!root) return;
    queue<Node*> q;
    q.push(root);
    while (!q.empty()) {
        Node* temp = q.front();
        q.pop();
        if (temp) {
            cout << temp->data << " ";
            q.push(temp->left);
            q.push(temp->right);
        } else {
            cout << "NULL ";
        }
    }
    cout << endl;
}

int main() {
    // Construct a binary tree for demonstration
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->right = new Node(5);
    root->right->left = new Node(6);
    root->right->right = new Node(7);

    // Serialize the tree
    vector<int> serializedTree = serialize(root);
    cout << "Serialized Tree: ";
    for (int val : serializedTree) {
        cout << val << " ";
    }
    cout << endl;

    // Deserialize the list back into a tree
    Node* deserializedRoot = deSerialize(serializedTree);
    cout << "Deserialized Tree (Level Order): ";
    printLevelOrder(deserializedRoot);

    return 0;
}
