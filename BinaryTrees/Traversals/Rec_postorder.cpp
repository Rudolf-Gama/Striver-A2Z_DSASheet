#include <iostream>
#include <vector>
using namespace std;

class Node {
public:
    int data;
    Node* left;
    Node* right;

    Node(int val) : data(val), left(nullptr), right(nullptr) {}
};

vector<int> postordercal(Node* root, vector<int>& ans) {
    if (!root) return ans;
    postordercal(root->left, ans);
    postordercal(root->right, ans);
    ans.push_back(root->data);
    return ans;
   }
   
vector <int> postOrder(Node* root)
{
  // Your code here
  vector<int> ans;
  return postordercal(root,ans);
}

int main() {
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->left = new Node(6);
    root->right->right = new Node(7);

    vector<int> result = postOrder(root);

    cout << "PostOrder Traversal: ";
    for (int val : result) {
        cout << val << " ";
    }
    cout << endl;

    // Clean up memory
    delete root->left->left;
    delete root->left->right;
    delete root->right->left;
    delete root->right->right;
    delete root->left;
    delete root->right;
    delete root;

    return 0;
}
