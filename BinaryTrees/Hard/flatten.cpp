#include<bits/stdc++.h>
using namespace std;

// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};



void flatten(TreeNode* root,TreeNode* &prev ) {
    if (root == NULL) return;
    flatten(root->right,prev);
    flatten(root->left,prev);

    root->right = prev;
    root->left = NULL;
    prev = root;
}

  void flattenST(TreeNode* root) {
       if(root==NULL) return ;
       stack<TreeNode*> st;
       st.push(root);
       while(!st.empty()){
        TreeNode* cur=st.top();
        st.pop();
        if(cur->right) st.push(cur->right);
        if(cur->left) st.push(cur->left);
        if(!st.empty()){
            cur->right=st.top();
            cur->left=NULL;
        }
       }
    }

// Helper function to print the flattened tree as a list
void printFlattenedTree(TreeNode* root) {
    while (root != NULL) {
        std::cout << root->val << " ";
        root = root->right;
    }
    std::cout << std::endl;
}

int main() {
    // Example tree:
    //      1
    //     / \
    //    2   5
    //   / \   \
    //  3   4   6
    
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(5);
    root->left->left = new TreeNode(3);
    root->left->right = new TreeNode(4);
    root->right->right = new TreeNode(6);
    TreeNode* prev =NULL;
    flatten(root,prev);
    
    std::cout << "Flattened tree: ";
    printFlattenedTree(root);
    
    return 0;
}
