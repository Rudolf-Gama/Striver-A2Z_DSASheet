#include <iostream>
#include <vector>
#include <climits>
using namespace std;

// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

TreeNode* build(vector<int>& preorder, int &i, int bound) {
    if (i == preorder.size() || preorder[i] > bound) return NULL;
    
    TreeNode* root = new TreeNode(preorder[i++]);
    root->left = build(preorder, i, root->val);
    root->right = build(preorder, i, bound);
    return root;
}

TreeNode* bstFromPreorder(vector<int>& preorder) {
    int i = 0;
    return build(preorder, i, INT_MAX);
}

// Utility function to print inorder traversal of the tree.
void printInorder(TreeNode* node) {
    if (node == NULL) return;
    printInorder(node->left);
    cout << node->val << " ";
    printInorder(node->right);
}

int main() {
    vector<int> preorder = {8, 5, 1, 7, 10, 12};
    TreeNode* root = bstFromPreorder(preorder);

    cout << "Inorder traversal of the constructed BST: ";
    printInorder(root);
    cout << endl;

    return 0;
}
