#include <iostream>
#include <queue>
#include <algorithm> // for max function

// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

int widthOfBinaryTree(TreeNode* root) {
    if (root == NULL) return 0;
    std::queue<std::pair<TreeNode*, int>> q;
    int ans = 0;
    q.push({root, 0});
    while (!q.empty()) {
        int s = q.size();
        int mini = q.front().second;
        int first = 0, last = 0;
        for (int i = 0; i < s; i++) {
            int id = q.front().second - mini;
            TreeNode* node = q.front().first;
            q.pop();
            if (i == 0) first = id;
            if (i == s - 1) last = id;
            if (node->left) q.push({node->left, 2*id + 1});
            if (node->right) q.push({node->right, 2*id + 2});
        }
        ans = std::max(ans, last - first + 1);
    }
    return ans;
}

int main() {
    // Creating a sample tree:
    //       1
    //      / \
    //     3   2
    //    / \   \ 
    //   5   3   9
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(3);
    root->right = new TreeNode(2);
    root->left->left = new TreeNode(5);
    root->left->right = new TreeNode(3);
    root->right->right = new TreeNode(9);

    std::cout << "Width of the binary tree: " << widthOfBinaryTree(root) << std::endl;
    return 0;
}
