#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

class Node {
public:
    int data;
    Node* left;
    Node* right;

    Node(int val) : data(val), left(nullptr), right(nullptr) {}
};

vector<int> findSpiral(Node* root) {
    if (!root) return {};  
    queue<Node*> q;
    vector<int> ans;
    q.push(root);
    int j = 0;

    while (!q.empty()) {
        int s = q.size();
        j++;
        vector<int> level;
        for (int i = 0; i < s; i++) {
            Node* temp = q.front();
            q.pop();
            if (temp->left) q.push(temp->left);
            if (temp->right) q.push(temp->right);
            level.push_back(temp->data);
        }
        if (j&1) reverse(level.begin(), level.end());
        for (auto it : level) {
            ans.push_back(it);
        }
    }
    return ans;
}

int main() {
    // Create the binary tree
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->left = new Node(6);
    root->right->right = new Node(7);

    vector<int> result = findSpiral(root);

    cout << "Spiral Order Traversal: ";
    for (int val : result) {
        cout << val << " ";
    }
    cout << endl;

    delete root->left->left;
    delete root->left->right;
    delete root->right->left;
    delete root->right->right;
    delete root->left;
    delete root->right;
    delete root;

    return 0;
}
