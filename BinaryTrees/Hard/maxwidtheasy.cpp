#include<bits/stdc++.h>
#include<queue>
using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;
    Node(int val) : data(val), left(NULL), right(NULL) {}
};

int getMaxWidth(Node* root) {
    if (!root) return 0;
    int maxWidth = -1;
    queue<Node *> q;
    q.push(root);
    while (!q.empty()) {
        int size = q.size();
        maxWidth = max(maxWidth, size);
        while (size--) {
            Node *temp = q.front();
            q.pop();
            if (temp->left) {
                q.push(temp->left);
            }
            if (temp->right) {
                q.push(temp->right);
            }
        }
    }
    return maxWidth;
}

int main() {
    Node* root = new Node(6);
    root->left = new Node(7);
    root->right = new Node(3);
    root->left->left = new Node(2);
    root->left->right = new Node(8);
    root->right->right = new Node(4);
    root->left->left->left = new Node(3);
    root->left->left->right = new Node(3);
    root->left->right->left = new Node(1);
    root->left->right->right = new Node(8);
    root->left->right->right->right = new Node(4);

    int width = getMaxWidth(root);
    cout<<width;

    return 0;
}
